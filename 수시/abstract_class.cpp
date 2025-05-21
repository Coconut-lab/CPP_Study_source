#include <iostream>
#include <string>

// 추상 클래스 - 최소 하나 이상의 순수 가상 함수를 포함
class Vehicle {
protected:
    std::string model;

public:
    Vehicle(const std::string& m) : model(m) {}

    // 순수 가상 함수 (pure virtual function) - 반드시 파생 클래스에서 구현해야 함
    virtual void start() = 0;

    // 일반 가상 함수 - 오버라이드 가능하지만 필수는 아님
    virtual void stop() {
        std::cout << "Vehicle stopped" << std::endl;
    }

    // 비가상 함수
    void displayModel() {
        std::cout << "Model: " << model << std::endl;
    }

    // 가상 소멸자
    virtual ~Vehicle() {}
};

// 구체 클래스 (Concrete class)
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& m, int doors) : Vehicle(m), numDoors(doors) {}

    // 순수 가상 함수 구현 (필수)
    void start() override {
        std::cout << "Car " << model << " started with key" << std::endl;
    }

    // 일반 가상 함수 오버라이드 (선택)
    void stop() override {
        std::cout << "Car " << model << " stopped with brake" << std::endl;
    }

    // Car 클래스 고유 메서드
    void honk() {
        std::cout << "Beep! Beep!" << std::endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& m) : Vehicle(m) {}

    // 순수 가상 함수 구현 (필수)
    void start() override {
        std::cout << "Motorcycle " << model << " started with kickstart" << std::endl;
    }

    // Motorcycle 클래스만의 메서드
    void wheelie() {
        std::cout << "Performing a wheelie!" << std::endl;
    }
};

int main() {
    // Vehicle vehicle("Generic");  // 오류: 추상 클래스는 인스턴스화할 수 없음

    Car car("Toyota", 4);
    Motorcycle motorcycle("Harley");

    // 다형성을 통한 메서드 호출
    Vehicle* vehicles[2] = {&car, &motorcycle};

    for (Vehicle* v : vehicles) {
        v->displayModel();  // 비가상 메서드
        v->start();         // 오버라이드된 순수 가상 메서드
        v->stop();          // 오버라이드된 일반 가상 메서드
        std::cout << "-------------------" << std::endl;
    }

    // 특정 타입으로 다운캐스팅하여 고유 메서드 호출
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