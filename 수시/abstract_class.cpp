#include <iostream>
#include <string>

// �߻� Ŭ���� - �ּ� �ϳ� �̻��� ���� ���� �Լ��� ����
class Vehicle {
protected:
    std::string model;

public:
    Vehicle(const std::string& m) : model(m) {}

    // ���� ���� �Լ� (pure virtual function) - �ݵ�� �Ļ� Ŭ�������� �����ؾ� ��
    virtual void start() = 0;

    // �Ϲ� ���� �Լ� - �������̵� ���������� �ʼ��� �ƴ�
    virtual void stop() {
        std::cout << "Vehicle stopped" << std::endl;
    }

    // �񰡻� �Լ�
    void displayModel() {
        std::cout << "Model: " << model << std::endl;
    }

    // ���� �Ҹ���
    virtual ~Vehicle() {}
};

// ��ü Ŭ���� (Concrete class)
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& m, int doors) : Vehicle(m), numDoors(doors) {}

    // ���� ���� �Լ� ���� (�ʼ�)
    void start() override {
        std::cout << "Car " << model << " started with key" << std::endl;
    }

    // �Ϲ� ���� �Լ� �������̵� (����)
    void stop() override {
        std::cout << "Car " << model << " stopped with brake" << std::endl;
    }

    // Car Ŭ���� ���� �޼���
    void honk() {
        std::cout << "Beep! Beep!" << std::endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& m) : Vehicle(m) {}

    // ���� ���� �Լ� ���� (�ʼ�)
    void start() override {
        std::cout << "Motorcycle " << model << " started with kickstart" << std::endl;
    }

    // Motorcycle Ŭ�������� �޼���
    void wheelie() {
        std::cout << "Performing a wheelie!" << std::endl;
    }
};

int main() {
    // Vehicle vehicle("Generic");  // ����: �߻� Ŭ������ �ν��Ͻ�ȭ�� �� ����

    Car car("Toyota", 4);
    Motorcycle motorcycle("Harley");

    // �������� ���� �޼��� ȣ��
    Vehicle* vehicles[2] = {&car, &motorcycle};

    for (Vehicle* v : vehicles) {
        v->displayModel();  // �񰡻� �޼���
        v->start();         // �������̵�� ���� ���� �޼���
        v->stop();          // �������̵�� �Ϲ� ���� �޼���
        std::cout << "-------------------" << std::endl;
    }

    // Ư�� Ÿ������ �ٿ�ĳ�����Ͽ� ���� �޼��� ȣ��
    Car* carPtr = dynamic_cast<Car*>(vehicles[0]);
    if (carPtr) {
        carPtr->honk();
    }

    Motorcycle* motorcyclePtr = dynamic_cast<Motorcycle*>(vehicles[1]);
    if (motorcyclePtr) {
        motorcyclePtr->wheelie();
    }

    return 0;
}