#include <iostream>
using namespace std;

// int add(int a[], int n) {
//     int s = 0;
//     for (int i = 0; i < n; i++) {
//         s += a[i];
//     }
//     return s;
// }
//
// int add(int a[], int n, int b[]) {
//     int s = 0;
//     for (int i = 0; i < n; i++) {
//         s += a[i] + b[i];
//     }
//     return s;
// }

int add(int a[], int n, int b[] = NULL) {
    int s = 0;
    if (b == NULL) {
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            s += a[i] + b[i];
        }
    }
    return s;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, 5);
    int d = add(a, 5, b);
    cout << c << endl;
    cout << d << endl;
    
    return 0;
}