#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class INotification {
public:
    virtual ~INotification() {}
    virtual string getContent() = 0;
};

class SimpleNotification : public INotification {
private:
    string text;
public:
    SimpleNotification(string text) : text(text) {}
    string getContent() override {
        return this->text;
    }
};

class ImportantNotification : public INotification {
private:
    string text;
public:
    ImportantNotification(string text) : text(text) {}
    string getContent() override {
        return "[IMPORTANT] " + this->text;
    }
};

class INotificationDecorator : public INotification {
protected:
    INotification* notification;
public:
    virtual ~INotificationDecorator() { 
        delete notification; 
    }
    INotificationDecorator(INotification* notification) : notification(notification) {}
};

class TimeStampDecorator : public INotificationDecorator {
public:
    TimeStampDecorator(INotification* notification) : INotificationDecorator(notification) {}
    string getContent() override {
        return "[10th July 2011 08:30] " + notification->getContent();
    }
};

class SignatureDecorator : public INotificationDecorator {
private:
    string signature;
public:
    SignatureDecorator(INotification* notification, string signature) 
        : INotificationDecorator(notification), signature(signature) {}
    string getContent() override {
        return notification->getContent() + " -- signed by " + signature + " ---";
    }
};


class INotificationStrategy {
public:
    virtual void sendNotification(string content) = 0;
    virtual ~INotificationStrategy() {}
};

class EmailStrategy : public INotificationStrategy {
private:
    string emailId;
public:
    EmailStrategy(string email) : emailId(email) {}
    void sendNotification(string content) override {
        cout << "Sending Email to [" << emailId << "]: " << content << "\n";
    }
};

class PopUpStrategy : public INotificationStrategy {
public:
    void sendNotification(string content) override {
        cout << "Displaying PopUp Alert: " << content << "\n";
    }
};

class SMSStrategy : public INotificationStrategy {
private:
    string phoneNo;
public:
    SMSStrategy(string phoneNo) : phoneNo(phoneNo) {}
    void sendNotification(string content) override {
        cout << "Sending SMS to [" << phoneNo << "]: " << content << "\n";
    }
};

class IObserver;

class IObservable {
protected:
    vector<IObserver*> observerlist;
    INotification* currentNotification;
public:
    virtual ~IObservable() { delete currentNotification; }
    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};

class NotificationObservable : public IObservable {
public:
    NotificationObservable() {
        this->currentNotification = nullptr;
    }
    
    void addObserver(IObserver* obs) override {
        this->observerlist.push_back(obs);
    }
    
    void removeObserver(IObserver* obs) override {
        observerlist.erase(remove(observerlist.begin(), observerlist.end(), obs), observerlist.end());
    }
    
    void notifyObservers() override; 
    
    INotification* getNotification() {
        return currentNotification;
    }
    
    string NotificationContent() {
        return currentNotification ? currentNotification->getContent() : "";
    }
    
    void setNotification(INotification* notification) {
        if (currentNotification != nullptr) {
            delete currentNotification; 
        }
        currentNotification = notification;
        notifyObservers();
    }
};

class IObserver {
protected:
    NotificationObservable* notificationObservable;
public:
    virtual void update() = 0;
    IObserver(NotificationObservable* observable) : notificationObservable(observable) {}
    virtual ~IObserver() {}
};

inline void NotificationObservable::notifyObservers() {
    for (auto observer : observerlist) {
        observer->update();
    }
}

class Logger : public IObserver {
public:
    Logger(NotificationObservable* notificationObservable) : IObserver(notificationObservable) {}
    void update() override {
        cout << "[LOGGER LOG]: " << notificationObservable->NotificationContent() << "\n\n";
    }
};

class NotificationEngine : public IObserver {
private:
    vector<INotificationStrategy*> list;
public:
    NotificationEngine(NotificationObservable* notificationObservable) : IObserver(notificationObservable) {}
    
    void addSource(INotificationStrategy* ns) {
        list.push_back(ns);
    }
    
    void removeSource(INotificationStrategy* ns) {
        list.erase(remove(list.begin(), list.end(), ns), list.end());
    }
    
    void update() override {
        for (auto strategy : list) {
            strategy->sendNotification(notificationObservable->NotificationContent());
        }
    }
};



int main() {
    NotificationObservable* appPublisher = new NotificationObservable();

    Logger* sysLogger = new Logger(appPublisher);
    NotificationEngine* routerEngine = new NotificationEngine(appPublisher);
    
    appPublisher->addObserver(sysLogger);
    appPublisher->addObserver(routerEngine);

    EmailStrategy* devEmail = new EmailStrategy("ops-team@company.com");
    SMSStrategy* adminSMS = new SMSStrategy("+1-555-0199");
    PopUpStrategy* uiPopUp = new PopUpStrategy();
    
    routerEngine->addSource(devEmail);
    routerEngine->addSource(adminSMS);
    routerEngine->addSource(uiPopUp);

    cout << "--- Dispatching Notification Bundle 1 ---\n";
    INotification* messageOne = new TimeStampDecorator(
                                    new SignatureDecorator(
                                        new ImportantNotification("Critical Cluster Memory Usage > 92%"), 
                                        "KernelMonitor"
                                    )
                                 );
    appPublisher->setNotification(messageOne);

    cout << "\n--- Dispatching Notification Bundle 2 (Dynamic Update Check) ---\n";
    INotification* messageTwo = new TimeStampDecorator(
                                    new SimpleNotification("Routine backup cycle completed cleanly.")
                                 );
    appPublisher->setNotification(messageTwo);

    delete devEmail;
    delete adminSMS;
    delete uiPopUp;
    delete sysLogger;
    delete routerEngine;
    delete appPublisher; 

    return 0;
}