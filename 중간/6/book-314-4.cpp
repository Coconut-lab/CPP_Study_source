#include <iostream>
using namespace std;

int big(int a, int b) {
    int result = (a > b) ? a : b;
    return (result > 100) ? 100 : result;
}

int big(int a, int b, int max) {
    int result = (a > b) ? a : b;
    return (result > max) ? max : result;
}

int main() {
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);

    cout << x << ' ' << y << ' ' << z << endl;

    return 0;
}