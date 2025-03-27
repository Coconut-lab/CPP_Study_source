#include <iostream>
using namespace std;

int main() {
    // 5개의 정수를 저장할 배열 선언
    int numbers[5];

    // 사용자로부터 5개의 정수 입력 받기
    cout << "정수 5개 입력>> ";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // 합계 계산
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // 평균 계산 (소수점 결과를 얻기 위해 double로 형변환)
    double average = (sum) / 5;

    // 계산된 평균 출력
    cout << "평균 " << average << endl;

    return 0;
}