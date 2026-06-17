#include <bits/stdc++.h>
using namespace std;

// Base Interface
class ICharacter {
    public:
        virtual string functionality() = 0;
        virtual ~ICharacter() {}
};

// Concrete Components
class Mario : public ICharacter {
    public:
        string functionality() override {
            return "Character is Mario";
        }
};

class Sonic : public ICharacter {
    public:
        string functionality() override {
            return "Character is Sonic";
        }
};

// Base Decorator (Implements ICharacter)
class Decorator : public ICharacter {
    protected: // Changed to protected so subclasses can access it if needed
        ICharacter* ch;
    public:
        Decorator(ICharacter* ch) : ch(ch) {}
        
        // Destructor cleans up the wrapped object to prevent memory leaks
        virtual ~Decorator() {
            delete ch; 
        }
};

// Concrete Decorator 1
class Fly : public Decorator {
    public:
        Fly(ICharacter* ch): Decorator(ch) {}
        
        string functionality() override { // Overriding the correct method
            return ch->functionality() + " can Fly,";
        }    
};

// Concrete Decorator 2
class Gun : public Decorator {
    public:
        Gun(ICharacter* ch): Decorator(ch) {}
        
        string functionality() override { // Overriding the correct method
            return ch->functionality() + " can Shoot,";
        }    
};

// Concrete Decorator 3
class Jump : public Decorator {
    public:
        Jump(ICharacter* ch): Decorator(ch) {}
        
        string functionality() override { // Overriding the correct method
            return ch->functionality() + " can Jump,";
        }    
};

// Concrete Decorator 4
class Die : public Decorator {
    public:
        Die(ICharacter* ch): Decorator(ch) {}
        
        string functionality() override { // Overriding the correct method
            return ch->functionality() + " can Die,";
        }    
};


int main() {
    ICharacter* superMario = new Fly(new Gun(new Die((new Mario))));
    cout << superMario->functionality() << endl;
    // Clean up memory (The cascading destructor handles armedMario and mario)
    delete superMario; 
    return 0;
}