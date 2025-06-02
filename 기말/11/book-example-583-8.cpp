#include <iostream>
#include <string>
using namespace std;

class Circle {
    string name;
    int radius;
public:
    Circle(int radius = 1, string name = "") {
        this->radius = radius;
        this->name = name;
    }
    void print() {
        cout << "(반지름" << radius << "인 " << name <<  ")";
    }
};

int main() {
    int r; string w;
    Circle circle[2];

    for (int i = 0; i < 2; i++) {
        cout << "반지름 >> ";
        cin >> r;
        cout << "이름 >> ";
        cin >> w;

        circle[i] = Circle(r, w);
    }

    for (int i = 0; i < 2; i++) {
        circle[i].print();
    }

    return 0;
}