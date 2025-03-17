#include <iostream>  // ����� ��Ʈ�� ���̺귯�� ����
using namespace std;  // ǥ�� ���ӽ����̽� ��� ����

// Circle Ŭ���� ����
class Circle {
public:
    int radius;  // �������� �����ϴ� ��� ���� (������)
    double getArea();  // ���� ������ ����ϴ� ��� �Լ� ����
};

// Circle Ŭ������ getArea() ��� �Լ� ����
// Ŭ���� �ܺο��� ������ ���� ���� ���� ������(::)�� ���
double Circle::getArea() {
    return 3.14 * radius * radius;  // ���� ���� ��� (�� �� r��)
}

int main() {
    Circle donut;  // donut�̶�� �̸��� Circle ��ü ����
    donut.radius = 1;  // donut�� �������� 1�� ����
    double area = donut.getArea();  // donut�� ���� ����Ͽ� area ������ ����
    cout << "donut ������ " << area << endl;  // donut�� ���� ���

    Circle pizza;  // pizza��� �̸��� Circle ��ü ����
    pizza.radius = 30;  // pizza�� �������� 30���� ����
    area = pizza.getArea();  // pizza�� ���� ����Ͽ� area ������ ����
    cout << "pizza ������ " << area << endl;  // pizza�� ���� ���

    return 0;  // ���α׷� ���� ����
}