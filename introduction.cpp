/*
Write a ComplexNumber class and support + and – operator to perform addition
and subtraction operations.
*/
#include<bits/stdc++.h>
using namespace std;


class ComplexNumber {
    private:
        float real;
        float imag;
    public:
        ComplexNumber(float = 0.0,float = 0.0);
        ~ComplexNumber();
        ComplexNumber operator+(const ComplexNumber &c1);
        friend ComplexNumber operator-(const ComplexNumber &c1,const ComplexNumber &c2);
        void display();
};

ComplexNumber::ComplexNumber(float x,float y):real(x),imag(y){}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c1)
{
    return ComplexNumber(this->real+c1.real,this->imag+c1.imag);
}

ComplexNumber operator-(const ComplexNumber &c1,const ComplexNumber &c2)
{
    return ComplexNumber(c1.real-c2.real,c1.imag-c2.imag);
}


ComplexNumber::~ComplexNumber()
{
    cout<<"Here Goes the Object Out of Scope"<<endl;
}

void ComplexNumber::display()
{
    cout<<"Printing the Number::";
    cout<<this->real<<"+"<<this->imag<<"j"<<endl;
}
