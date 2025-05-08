// Main.cpp
#include <iostream>
#include "ATMachine.h"
using namespace std;

int main() {
    int select;
    // �� ��(100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ
    ATMachine atm(100, 50000, "admin");

    while(1) {
        atm.displayMenu();
        cout << "�޴��� �����ϼ���: ";
        cin >> select;
        cout << endl;

        switch(select) {
            case 1:
                atm.createAccount();
            break;
            case 2:
                atm.checkMoney();
            break;
            case 3:
                atm.closeAccount();
            break;
            case 4:
                atm.depositMoney();
            break;
            case 5:
                atm.widrawMoney();
            break;
            case 9:
                cout << "�̿��� �ּż� �����մϴ�." << endl;
            return 0;
            default:
                cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
        }
    }

    return 0;
}