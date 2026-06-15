#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton {
    private:
        static Singleton* instance;
        static mutex mtx;
        Singleton(){
            cout<<"Singleton Constructor Called"<<endl;
        }
    public:
        static Singleton* getInstance()
        {
            if(instance==nullptr)
            {
                lock_guard<mutex> lock(mtx); // Lock for thread Safety
                if(instance==nullptr) {
                    instance = new Singleton();
                }
            }
            return instance;
        }
};
mutex Singleton::mtx;
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}