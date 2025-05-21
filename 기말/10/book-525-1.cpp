#include <iostream>
using namespace std;

// ���׸� �Լ�(���ø�) - �پ��� ������ Ÿ�Կ� ���� ���� ū ���� ã��
template <typename T>
T biggest(T x[], int size) {
    T max = x[0]; // ù ��° ���Ҹ� �ִ밪���� �ʱ�ȭ
    
    for(int i = 1; i < size; i++) {
        if(x[i] > max) {
            max = x[i]; // �� ū ���� ã���� max ����
        }
    }
    
    return max;
}

int main() {
    // int �迭 ����
    int x[] = {1, 10, 100, 5, 4};
    cout << "int �迭: biggest(x, 5) = " << biggest(x, 5) << endl;
    
    // double �迭 ���� (���׸� �Լ��� Ư¡�� �����ֱ� ����)
    double y[] = {1.5, 10.2, 100.8, 5.3, 4.7};
    cout << "double �迭: biggest(y, 5) = " << biggest(y, 5) << endl;
    
    // char �迭 ���� (���׸� �Լ��� Ư¡�� �����ֱ� ����)
    char z[] = {'a', 'z', 'c', 'A', 'Z'};
    cout << "char �迭: biggest(z, 5) = " << biggest(z, 5) << endl;
    
    return 0;
}