#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}

    // ���� �Լ� - �Ļ� Ŭ�������� �������̵� ����
    virtual void makeSound() {
        std::cout << name << " makes a generic sound" << std::endl;
    }

    // �񰡻� �Լ� - �������̵� �Ұ�
    void eat() {
        std::cout << name << " is eating" << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}

    // makeSound �޼��� �������̵�
    void makeSound() override {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
    }

    // �θ� Ŭ������ �񰡻� �޼���� ����(hiding)��, �������̵� �ƴ�
    void eat() {
        std::cout << name << " is eating dog food" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}

    // makeSound �޼��� �������̵�
    void makeSound() override {
        std::cout << name << " meows: Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animal = new Animal("Generic animal");
    Animal* dog = new Dog("Buddy");
    Animal* cat = new Cat("Whiskers");

    // ���� ���ε��� ���� �� ��ü�� �������̵�� �޼��� ȣ��
    animal->makeSound();  // "Generic animal makes a generic sound"
    dog->makeSound();     // "Buddy barks: Woof! Woof!"
    cat->makeSound();     // "Whiskers meows: Meow! Meow!"

    // �񰡻� �Լ��� ���� ���ε� - ������ Ÿ�Կ� ���� ȣ��
    animal->eat();        // "Generic animal is eating"
    dog->eat();           // "Generic animal is eating" (Dog::eat�� ȣ����� ����)

    // Dog Ÿ������ ���� �����ϸ� ������ eat() �޼��� ȣ�� ����
    Dog directDog("Rex");
    directDog.eat();      // "Rex is eating dog food"

    delete animal;
    delete dog;
    delete cat;

    return 0;
}