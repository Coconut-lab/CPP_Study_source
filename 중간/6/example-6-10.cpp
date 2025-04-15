#include <iostream>
using namespace std;

// 클래스를 만들고 전역 함수들을 static 멤버로 캡슐하한 프로그램
class Math {
public:
    static int abs(int a) {
        return a > 0 ? a : -a;
    }
    static int max(int a, int b) {
        return a > b ? a : b;
    }
    static int min(int a, int b) {
        return a < b ? a : b;
    }
};

// 전역 함수들을 가진 좋지 않은 코딩 사례
int abs(int a) {
    return a > 0 ? a : -a;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    cout << abs(-5) << endl; // 5
    cout << max(10, 8) << endl; // 10
    cout << min(-3, -8) << endl; // 8

    cout << Math::abs(-5) << endl;
    cout << Math::max(10, 8) << endl;
    cout << Math::min(-3, -8) << endl;
    
    return 0;
}