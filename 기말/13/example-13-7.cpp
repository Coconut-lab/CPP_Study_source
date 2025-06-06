#include <iostream>
using namespace std;
#include "MyStach.h"

int main() {
    MyStack intStack;
    try {
        intStack.push(100);
        intStack.push(200);
        cout << intStack.pop() << endl;
        cout << intStack.pop() << endl;
        cout << intStack.pop() << endl;
    }
    catch (const char* s) {
        cerr << "예외 발생: " << s << endl;
    }
}