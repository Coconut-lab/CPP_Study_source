#include <iostream>
using namespace std;

class Base {
public:
    virtual void f() {
        cout << "Base::f() called" << endl;
    }
};

class Derived : public Base {
public:
    void f() {
        cout << "Derived::f() called" << endl;
    }
};

class GrandDerived : public Derived {
public:
    void f() {
        cout << "GrandDerived::f() called" << endl;
    }
};

int main() {
    GrandDerived g;

    Base *bp;
    Derived *dp;
    GrandDerived *gp;

    bp = dp = gp = &g;

    bp->f();  // 가상 함수이므로 실제 객체의 함수가 호출됨
    dp->f();  // 가상 함수이므로 실제 객체의 함수가 호출됨
    gp->f();  // 직접 GrandDerived의 함수 호출
}