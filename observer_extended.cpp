#include <bits/stdc++.h>
using namespace std;


class ISubscriber;
class IChannel;

class ISubscriber {
public:
    virtual void notify(IChannel* ch) = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
public:
    virtual void uploadVideo(string video) = 0;
    virtual string addSubscriber(ISubscriber* sub) = 0;
    virtual string removeSubscriber(ISubscriber* sub) = 0;
    virtual string getName() = 0;
    virtual string getLatestVideo() = 0;
    virtual ~IChannel() {}
};




class Subscriber : public ISubscriber{
private:
    string name;
    unordered_set<IChannel*> list;
public:
    Subscriber(string sname):name(sname) {}
    void Subscribe(IChannel* ch) 
    {
        if(list.find(ch)==list.end())
        {
            list.insert(ch);
            cout<<this->name<<" "<<ch->addSubscriber(this);
        }
    }
    void UnSubscribe(IChannel* ch)
    {
        if(list.find(ch)!=list.end())
        {
            list.erase(ch);
            cout<<this->name<<" "<<ch->removeSubscriber(this);
        }
    }
    void notify(IChannel *ch) override { 
        cout<<"Hey "<<this->name<<", "<<ch->getName()<< " uploaded a new Video Titled: "<< ch->getLatestVideo()<<endl;
    }
};


class Channel  : public IChannel {
private:
    unordered_set<ISubscriber*> list;
    vector<string> Videos;
    string name;
    string latestVideo;
public:
    
    Channel(string cname):name(cname) {}
    void uploadVideo(string video) override
    {
        this->latestVideo = video;
        Videos.push_back(this->getLatestVideo());
        notifySubscribers(this);
    }
    void notifySubscribers(IChannel* ch) {
        for(ISubscriber* sub : list)
            sub->notify(ch);   
    }
    string addSubscriber(ISubscriber* sub) override
    {
        if(list.find(sub)==list.end())
        {
            list.insert(sub);
            return "Subscribed to " + this->getName() + "\n";
        }
        return "Channel Not Found";
    }
    string removeSubscriber(ISubscriber* sub) override
    {
        if(list.find(sub)!=list.end())
        {
            list.erase(sub);
            return "Unsubscribed to " + this->getName() + "\n";
        }
        return "Channel Not Found";
    }
    string getName() override{
        return this->name;
    }
    string getLatestVideo() override{
        return this->latestVideo;
    }
};


int main()
{
    IChannel* c1 = new Channel("Gate Smashers");
    IChannel* c2 = new Channel("Striver");
    IChannel* c3 = new Channel("Abdul Bari");
    Subscriber* s1 = new Subscriber("Ryan");
    Subscriber* s2 = new Subscriber("Michelle");
    s1->Subscribe(c1);
    s1->Subscribe(c2);
    s2->Subscribe(c2);
    s2->Subscribe(c3);
    c1->uploadVideo("Operaing Systems");
    c2->uploadVideo("Femwick Tree");
    c3->uploadVideo("DSA Preparation Strategy");
    s1->UnSubscribe(c2);
    s2->UnSubscribe(c1);
    c3->uploadVideo("Djikstra Algorithm");
    return 0;
}