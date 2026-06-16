#include <bits/stdc++.h>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel{
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    unordered_set<ISubscriber*> subscribers;
    string name;
    string latestvideo;
public:
    Channel(const string &name)
    {
        this->name = name;
    }
    void subscribe(ISubscriber* subscriber)
    {
        if(subscribers.find(subscriber)==subscribers.end())
            subscribers.insert(subscriber);
    }
    void unsubscribe(ISubscriber* unsubscriber)
    {
        if(subscribers.find(unsubscriber)!=subscribers.end())
            subscribers.erase(unsubscriber);
    }
    void notifySubscribers() override {
        for(ISubscriber* sub : subscribers)
            sub->update();
    }
    void UploadVideo(const string& title)
    {
        latestvideo = title;
        cout<<"\n["<<name<<" uploaded \""<<title<<" \"]\n";
        notifySubscribers();
    }
    string getVideoData()
    {
        return "\n CheckOut our New Video: " + latestvideo + "\n";
    }
};


class Subscriber : public ISubscriber {
    private:
        string name;
        Channel* channel;
    public:
        Subscriber(const string& name,Channel* channel)
        {
            this->name = name;
            this->channel = channel;
        }
        void update() override {
            cout<<"Hey "<<name<<","<<this->channel->getVideoData();
        }
};


int main()
{
    Channel* channel = new Channel("CoderArmy");
    Subscriber* sub1 = new Subscriber("Varun",channel);
    Subscriber* sub2 = new Subscriber("Tarun",channel);
    channel->subscribe(sub1);
    channel->subscribe(sub2);
    channel->UploadVideo("Observer Pattern Tutorial");
    channel->unsubscribe(sub1);
    channel->UploadVideo("Decorator Pattern Tutorial");
    return 0;
}