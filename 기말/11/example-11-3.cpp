#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char cmd[80];
    cout << "cin.get(char*, int)�� ���ڿ��� �н��ϴ�." << endl;
    while (true) {
        cout << "�����ҷ��� exit�� �Է��ϼ���>> ";
        cin.get(cmd, 80); // ���ڿ��� �Է¹���
        if (strcmp(cmd, "exit") == 0) {
            cout << "���α׷��� �����մϴ�.....";
            return 0;
        }
        else {
            cin.ignore(1);
        }
    }
}