#include <iostream>
using namespace std;

int sum(int a, int b) {
    int s = 0;
    for (int i = a; i <= b; i++) {
        s += i;
    }
    return s;
}

int sum(int a) {
    int s = 0;
    for (int i = 0; i <= a; i++) {
        s += i;
    }
    return s;
}

int main() {
    cout << sum(3,5) << endl; // 3 + 4 + 5 = 12
    cout << sum(3) << endl; // 0 + 1 + 2 + 3 = 6
    cout << sum(100) << endl; // 0 + 1 + ... + 100 = 5050
    
    return 0;
}