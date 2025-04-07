#include <iostream>
using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(Circle& c); // 복사 생성자
    Circle() {
        radius = 1;
    }
    Circle(int radius) {
        this -> radius = radius;
    }
    double getArea() {
        3.14 * radius * radius;
    }
};

Circle::Circle(Circle& c) {
    this -> radius = c.radius;
    cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main() {
    Circle src(30);
    Circle dest(src); // 복사 생성자 호출

    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;
    
    return 0;
}