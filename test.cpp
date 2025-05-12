#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "동물이 소리를 냅니다." << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "멍멍!" << endl;
    }

    void fetch() {
        cout << "공을 가져옵니다!" << endl;
    }
};

int main() {
    Dog dog;

    // 업캐스팅
    Animal* animal = &dog;

    // C 스타일 다운캐스팅 (명시적 캐스트 연산자 없이)
    Dog* dogPtr = (Dog*)animal;

    // 이제 Dog 클래스의 메서드 사용 가능

    dogPtr -> Animal::speak();
    animal -> speak();
    dogPtr -> fetch();  // "공을 가져옵니다!" 출력

    return 0;
}