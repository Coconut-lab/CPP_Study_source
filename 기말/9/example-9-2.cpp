#include <iostream>
using namespace std;

class Base {
public:
    virtual void f() {cout << "Base::f() called" << endl;}
};

class Derived : public Base {
public:
    virtual void f() {cout << "Derived::f() called" << endl;}
};

int main() {
    Derived d, *pDer;
    pDer = &d;
    pDer -> f(); // Derived::f() called

    Base *pBase;
    pBase = pDer;   // Upcasting
    pBase -> f(); // Derived::f() called
}