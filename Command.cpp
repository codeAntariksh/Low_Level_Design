#include <bits/stdc++.h>
using namespace std;

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Fan {
public:
    void on(){
        cout<<"Fan is Turned On"<<endl;
    }
    void off(){
        cout<<"Fan is Turned Off"<<endl;
    }
};

class IFan : public ICommand{
private:
    Fan* f;
public:
    IFan(){
        f = new Fan();
    }
    void execute() override {
        this->f->on();
    }
    void undo() override {
        this->f->off();
    }
};


class Lamp {
public:
    void on(){
        cout<<"Lamp is Turned On"<<endl;
    }
    void off(){
        cout<<"Lamp is Turned Off"<<endl;
    }
};

class ILamp : public ICommand{
private:
    Lamp* f;
public:
    ILamp(){
        f = new Lamp();
    }
    void execute() override {
        this->f->on();
    }
    void undo() override {
        this->f->off();
    }
};



class Light {
public:
    void on(){
        cout<<"Light is Turned On"<<endl;
    }
    void off(){
        cout<<"Light is Turned Off"<<endl;
    }
};

class ILight : public ICommand{
private:
    Light* f;
public:
    ILight(){
        f = new Light();
    }
    void execute() override {
        this->f->on();
    }
    void undo() override {
        this->f->off();
    }
};

class Remote {
private:
    vector<ICommand*> arr;
    vector<bool> state;
public:
    void setCommand(ICommand* comm){
        this->arr.push_back(comm);
        this->state.push_back(false);
    }
    void PressButton(int i){
        if(i>=arr.size())
        {
            cout<<"Such Command Doesn't Exist"<<endl;
            return;
        }
        if(state[i]==true) 
        {
            this->arr[i]->undo();
            this->state[i] = false;
        }
        else 
        {
            this->arr[i]->execute();
            this->state[i] = true;
        }
    }
};


int main(){
    Remote* remote = new Remote();
    ICommand* comm = new IFan();
    ICommand* comm2 = new ILamp();
    ICommand* comm3 = new ILight();
    remote->setCommand(comm);
    remote->setCommand(comm3);
    remote->setCommand(comm2);
    remote->PressButton(1);
    remote->PressButton(5);
    remote->PressButton(0);
    remote->PressButton(0);
    remote->PressButton(2);
    remote->PressButton(2);
    return 0;
}