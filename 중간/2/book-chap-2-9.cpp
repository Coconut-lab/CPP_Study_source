#include <iostream>
using namespace std;

int main() {
    char name[20];
    char address[100];
    int age;

    cout << "�̸���? ";
    cin.getline(name, 20, '\n');
    cout << "�ּҴ�? ";
    cin.getline(address, 100, '\n');
    cout << "���̴�? ";
    cin >> age;

    cout << name << ", " << address << ", " << age << "��" << endl;
    
    return 0;
}