#include <iostream>
using namespace std;

void fillLine() {
    for (int i = 0; i < 25; i++) {
        cout << endl;
    }
}

void fillLine(int n = 25, char c = '*') {
    for (int i = 0; i < n; i++) {
        cout << c;
    }
    cout << endl;
}

int main() {
    fillLine();
    fillLine(10, '%');
    
    return 0;
}