#include <iostream>

// 기본 클래스
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }

    // 소멸자는 항상 가상으로 선언
    virtual ~Shape() {}
};

// 파생 클래스
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    // Circle 클래스만의 고유 메서드
    void calculateArea() {
        std::cout << "Circle area: " << 3.14 * radius * radius << std::endl;
    }
};

int main() {
    // 업캐스팅: 자식 클래스 -> 부모 클래스 (암시적 변환 가능)
    Circle* circle = new Circle(5.0);
    Shape* shape = circle;  // 업캐스팅 - 자동으로 수행됨

    // 가상 함수 호출 - 동적 바인딩에 의해 Circle의 draw()가 호출됨
    shape->draw();

    // 다운캐스팅: 부모 클래스 -> 자식 클래스 (명시적 캐스팅 필요)
    // dynamic_cast는 안전한 다운캐스팅을 제공 - 실패 시 nullptr 반환
    Circle* circleAgain = dynamic_cast<Circle*>(shape);

    if (circleAgain) {
        // Circle의 고유 메서드 호출
        circleAgain->calculateArea();
    }

    // 안전하지 않은 다운캐스팅 - 런타임 확인 없음
    Circle* unsafeCircle = static_cast<Circle*>(shape);
    unsafeCircle->calculateArea();

    delete circle; // 메모리 해제

    return 0;
}