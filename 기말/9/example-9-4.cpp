#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "-- shape --";
    }
};

class Circle : public Shape {
public:
    virtual void draw() {
        Shape::draw();
        cout << "Circle" << endl;
    }
};

int main() {
    Circle circle;
    Shape* pShape = &circle;

    pShape -> draw();
    pShape -> Shape::draw();
}