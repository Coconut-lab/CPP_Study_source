#include <iostream>
using namespace std;

// 제네릭 함수(템플릿) - 다양한 데이터 타입에 대해 가장 큰 값을 찾음
template <typename T>
T biggest(T x[], int size) {
    T max = x[0]; // 첫 번째 원소를 최대값으로 초기화
    
    for(int i = 1; i < size; i++) {
        if(x[i] > max) {
            max = x[i]; // 더 큰 값을 찾으면 max 갱신
        }
    }
    
    return max;
}

int main() {
    // int 배열 예제
    int x[] = {1, 10, 100, 5, 4};
    cout << "int 배열: biggest(x, 5) = " << biggest(x, 5) << endl;
    
    // double 배열 예제 (제네릭 함수의 특징을 보여주기 위함)
    double y[] = {1.5, 10.2, 100.8, 5.3, 4.7};
    cout << "double 배열: biggest(y, 5) = " << biggest(y, 5) << endl;
    
    // char 배열 예제 (제네릭 함수의 특징을 보여주기 위함)
    char z[] = {'a', 'z', 'c', 'A', 'Z'};
    cout << "char 배열: biggest(z, 5) = " << biggest(z, 5) << endl;
    
    return 0;
}