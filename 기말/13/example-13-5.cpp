#include <iostream>
using namespace std;

int getExp(int base, int exp) {
    if (base <= 0 || exp <= 0) {
        throw "음수 사용 불가";
    }
    int value = 1;

    for (int n = 0; n < exp; n++) {
        value *= base;
    }

    return value;
}

int main() {
    int v = 0;
    try {
        v = getExp(2, 3);
        cout << "2^3 = " << v << endl;

        v = getExp(2, -3);
        cout << "2^-3 = " << v << endl;
    } catch (const char* msg) {
        cout << "예외 발생: " << msg << endl;
    }
    
}