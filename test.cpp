#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "������ �Ҹ��� ���ϴ�." << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "�۸�!" << endl;
    }

    void fetch() {
        cout << "���� �����ɴϴ�!" << endl;
    }
};

int main() {
    Dog dog;

    // ��ĳ����
    Animal* animal = &dog;

    // C ��Ÿ�� �ٿ�ĳ���� (����� ĳ��Ʈ ������ ����)
    Dog* dogPtr = (Dog*)animal;

    // ���� Dog Ŭ������ �޼��� ��� ����

    dogPtr -> Animal::speak();
    animal -> speak();
    dogPtr -> fetch();  // "���� �����ɴϴ�!" ���

    return 0;
}