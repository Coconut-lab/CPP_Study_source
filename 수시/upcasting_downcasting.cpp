#include <iostream>

// �⺻ Ŭ����
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }

    // �Ҹ��ڴ� �׻� �������� ����
    virtual ~Shape() {}
};

// �Ļ� Ŭ����
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    // Circle Ŭ�������� ���� �޼���
    void calculateArea() {
        std::cout << "Circle area: " << 3.14 * radius * radius << std::endl;
    }
};

int main() {
    // ��ĳ����: �ڽ� Ŭ���� -> �θ� Ŭ���� (�Ͻ��� ��ȯ ����)
    Circle* circle = new Circle(5.0);
    Shape* shape = circle;  // ��ĳ���� - �ڵ����� �����

    // ���� �Լ� ȣ�� - ���� ���ε��� ���� Circle�� draw()�� ȣ���
    shape->draw();

    // �ٿ�ĳ����: �θ� Ŭ���� -> �ڽ� Ŭ���� (����� ĳ���� �ʿ�)
    // dynamic_cast�� ������ �ٿ�ĳ������ ���� - ���� �� nullptr ��ȯ
    Circle* circleAgain = dynamic_cast<Circle*>(shape);

    if (circleAgain) {
        // Circle�� ���� �޼��� ȣ��
        circleAgain->calculateArea();
    }

    // �������� ���� �ٿ�ĳ���� - ��Ÿ�� Ȯ�� ����
    Circle* unsafeCircle = static_cast<Circle*>(shape);
    unsafeCircle->calculateArea();

    delete circle; // �޸� ����

    return 0;
}