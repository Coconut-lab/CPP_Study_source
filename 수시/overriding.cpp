#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    // 가상 함수 - 파생 클래스에서 오버라이드 가능
    virtual void makeSound() {
        std::cout << name << " makes a generic sound" << std::endl;
    }

    // 비가상 함수 - 오버라이드 불가
    void eat() {
        std::cout << name << " is eating" << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    // makeSound 메서드 오버라이딩
    void makeSound() override {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
    }

    // 부모 클래스의 비가상 메서드는 숨김(hiding)됨, 오버라이딩 아님
    void eat() {
        std::cout << name << " is eating dog food" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}

    // makeSound 메서드 오버라이딩
    void makeSound() override {
        std::cout << name << " meows: Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animal = new Animal("Generic animal");
    Animal* dog = new Dog("Buddy");
    Animal* cat = new Cat("Whiskers");

    // 동적 바인딩에 의해 각 객체의 오버라이드된 메서드 호출
    animal->makeSound();  // "Generic animal makes a generic sound"
    dog->makeSound();     // "Buddy barks: Woof! Woof!"
    cat->makeSound();     // "Whiskers meows: Meow! Meow!"

    // 비가상 함수는 정적 바인딩 - 포인터 타입에 따라 호출
    animal->eat();        // "Generic animal is eating"
    dog->eat();           // "Generic animal is eating" (Dog::eat가 호출되지 않음)

    // Dog 타입으로 직접 접근하면 숨겨진 eat() 메서드 호출 가능
    Dog directDog("Rex");
    directDog.eat();      // "Rex is eating dog food"

    delete animal;
    delete dog;
    delete cat;

    return 0;
}