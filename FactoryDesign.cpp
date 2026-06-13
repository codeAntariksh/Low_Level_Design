#include <bits/stdc++.h>
using namespace std;

// Burgers

class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger() {};
};

class ClassicBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Classic Burger\n";
        }
};

class ClassicWheatBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Healthy Classic Burger\n";
        }
};

class PremiumBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Premium Burger\n";
        }
};


class PremiumWheatBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Healthy Premium Burger\n";
        }
};

class StandardBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Standard Burger\n";
        }
};

class StandardWheatBurger : public Burger{
    public:
        void prepare() override {
            cout<<"This is a Healthy Standard Burger\n";
        }
};

// Garlic B
class GarlicB{
    public:
        virtual void prepare() = 0;
        virtual ~GarlicB() {};
};

class ClassicGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Classic GarlicB\n";
        }
};

class ClassicWheatGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Healthy Classic GarlicB\n";
        }
};

class PremiumGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Premium GarlicB\n";
        }
};


class PremiumWheatGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Healthy Premium GarlicB\n";
        }
};

class StandardGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Standard GarlicB\n";
        }
};

class StandardWheatGarlicB : public GarlicB{
    public:
        void prepare() override {
            cout<<"This is a Healthy Standard GarlicB\n";
        }
};



class Factory{
    public:
    /*    
    Burger* PrepareBurger(string type)
        {
            if(type=="standard")
                return new StandardBurger();
            else if(type=="premium")
                return new PremiumBurger();
            else if(type=="classic")
                return new ClassicBurger();
        }
    */
   virtual GarlicB* PrepareGarlicB(string type) = 0;
    virtual Burger* PrepareBurger(string type) = 0;
   virtual ~Factory() {};
};

class SinghBurger : public Factory {
    Burger* PrepareBurger(string type) override
        {
            if(type=="standard")
                return new StandardBurger();
            else if(type=="premium")
                return new PremiumBurger();
            else if(type=="classic")
                return new ClassicBurger();
        }
    GarlicB* PrepareGarlicB(string type) override
        {
            if(type=="standard")
                return new StandardGarlicB();
            else if(type=="premium")
                return new PremiumGarlicB();
            else if(type=="classic")
                return new ClassicGarlicB();
        }
};


class KingBurger : public Factory {
    Burger* PrepareBurger(string type) override
        {
            if(type=="standard healthy")
                return new StandardWheatBurger();
            else if(type=="premium healthy")
                return new PremiumWheatBurger();
            else if(type=="classic healthy")
                return new ClassicWheatBurger();
        }
    GarlicB* PrepareGarlicB(string type) override
        {
            if(type=="standard healthy")
                return new StandardWheatGarlicB();
            else if(type=="premium healthy")
                return new PremiumWheatGarlicB();
            else if(type=="classic healthy")
                return new ClassicWheatGarlicB();
        }
};

int main()
{
    Factory* factory1 = new SinghBurger();
    Burger* bg1 = factory1->PrepareBurger("classic");
    GarlicB* g1 = factory1->PrepareGarlicB("premium");
    bg1->prepare();
    g1->prepare();
    Factory* factory2 = new KingBurger();
    Burger* bg2 = factory2->PrepareBurger("classic healthy");
    GarlicB* g2 = factory2->PrepareGarlicB("premium healthy");
    g2->prepare();
    bg2->prepare();
    return 0;
}