#include <iostream>
using namespace std;

int main() {
    // 5���� ������ ������ �迭 ����
    int numbers[5];

    // ����ڷκ��� 5���� ���� �Է� �ޱ�
    cout << "���� 5�� �Է�>> ";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // �հ� ���
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // ��� ��� (�Ҽ��� ����� ��� ���� double�� ����ȯ)
    double average = (sum) / 5;

    // ���� ��� ���
    cout << "��� " << average << endl;

    return 0;
}