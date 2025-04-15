#include <iostream>
using namespace std;

// Ŭ������ ����� ���� �Լ����� static ����� ĸ������ ���α׷�
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

// ���� �Լ����� ���� ���� ���� �ڵ� ���
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