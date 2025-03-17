#include <iostream>  // 입출력 스트림 라이브러리 포함
using namespace std;  // 표준 네임스페이스 사용 선언

// Circle 클래스 정의
class Circle {
public:
    int radius;  // 반지름을 저장하는 멤버 변수 (정수형)
    double getArea();  // 원의 면적을 계산하는 멤버 함수 선언
};

// Circle 클래스의 getArea() 멤버 함수 구현
// 클래스 외부에서 구현할 때는 범위 지정 연산자(::)를 사용
double Circle::getArea() {
    return 3.14 * radius * radius;  // 원의 면적 계산 (π × r²)
}

int main() {
    Circle donut;  // donut이라는 이름의 Circle 객체 생성
    donut.radius = 1;  // donut의 반지름을 1로 설정
    double area = donut.getArea();  // donut의 면적 계산하여 area 변수에 저장
    cout << "donut 면적은 " << area << endl;  // donut의 면적 출력

    Circle pizza;  // pizza라는 이름의 Circle 객체 생성
    pizza.radius = 30;  // pizza의 반지름을 30으로 설정
    area = pizza.getArea();  // pizza의 면적 계산하여 area 변수에 저장
    cout << "pizza 면적은 " << area << endl;  // pizza의 면적 출력

    return 0;  // 프로그램 정상 종료
}