#include <bits/stdc++.h>
using namespace std;
 
// Strategies

class WalkableRobot
{
    public:
        virtual void walk() = 0;
};
 
class NormalWalk : public WalkableRobot {
    public:    
        void walk() override{
            cout<<"Normal Walk"<<endl;
        }
};

class NoWalk : public WalkableRobot {
    public:    
        void walk() override{
            cout<<"No Walk"<<endl;
        }
};


class FlyableRobot
{
    public:
        virtual void fly() = 0;
};

class NormalFly : public FlyableRobot {
    public:    
        void fly() override {
            cout<<"Flying Normally"<<endl;
        }
};

class NoFly : public FlyableRobot {
    public:    
        void fly() override {
            cout<<"Not Flying"<<endl;
        }
};

class JetFly : public FlyableRobot {
    public:  
        void fly() override {
            cout<<"Flying With a Jet"<<endl;
        }
};


class TalkableRobot
{
    public:
        virtual void talk() = 0;
};

class NoTalk : public TalkableRobot {
    public:
        void talk() override{
            cout<<"Not Talking"<<endl;
        }
};

class NormalTalk : public TalkableRobot {
    public:
        void talk() override{
            cout<<"Talking Normally"<<endl;
        }
};

// Client

class Robot {
   protected:
    WalkableRobot* walkBehavior;
    FlyableRobot* flyBehavior;
    TalkableRobot* talkBehavior;
    public:
        Robot(WalkableRobot* walk,TalkableRobot* talk,FlyableRobot* fly): walkBehavior(walk),flyBehavior(fly),talkBehavior(talk) {}
        void walk(){
            walkBehavior->walk();
        }
        void fly(){
            flyBehavior->fly();
        }
        void talk(){
            talkBehavior->talk();
        }
        virtual void projection() = 0;
};

// Concrete Robot Types

class CompanionRobot : public Robot {
    public:
        CompanionRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f) {}
        void projection() override{
            cout<<"Displaying Friendly Companion Features:"<<endl;
        }
};

class WorkerRobot : public Robot {
    public:
        WorkerRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f) {}
        void projection() override{
            cout<<"Displaying Worker Features:"<<endl;
        }
};

int main()
{
    Robot* r1 = new CompanionRobot(new NormalWalk(),new NormalTalk(),new NoFly());
    r1->projection();
    r1->walk();
    r1->talk();
    r1->fly();

    cout<<endl;

    Robot* r2 = new WorkerRobot(new NormalWalk(),new NoTalk(),new NoFly());
    r2->projection();
    r2->walk();
    r2->talk();
    r2->fly();

    delete r1;
    delete r2;

    return 0;
}