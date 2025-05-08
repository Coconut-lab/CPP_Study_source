// ATMachine.cpp
#include "ATMachine.h"
#include <iostream>
#include <random>
using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {
    pAcctArray = new Account[size];
    nMachineBalance = balance;
    nMaxAccountNum = size;
    nCurrentAccountNum = 0;
    strManagerPassword = password;
}

ATMachine::~ATMachine() {
    delete[] pAcctArray;
}

void ATMachine::displayMenu() {
    cout << "----------------------" << endl;
    cout << "-    TUKOREA BANK    -" << endl;
    cout << "----------------------" << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. ���� ��ȸ" << endl;
    cout << "3. ���� ����" << endl;
    cout << "4. ���� �Ա�" << endl;
    cout << "5. ���� ���" << endl;
    cout << "9. ���� ����" << endl;
    cout << "----------------------" << endl;
}

void ATMachine::createAccount() {
    if (nCurrentAccountNum >= nMaxAccountNum) {
        cout << "�� �̻� ���¸� ������ �� �����ϴ�." << endl;
        return;
    }

    string name, password;

    cout << "------ ���� ------" << endl;
    cout << "�̸� �Է�: ";
    cin >> name;
    cout << "��ȣ �Է�: ";
    cin >> password;

    // ���¹�ȣ ���� (200 ~ 900��) �������� ��ȣ ����
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(200, 900);
    int id = dis(gen);

    // �ߺ��� ���¹�ȣ�� �ִ��� Ȯ��
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            id = dis(gen); // ���ο� ���� ��ȣ ����
            i = -1; // ���� �ٽ� ����
        }
    }

    // ���� ����
    pAcctArray[nCurrentAccountNum].create(id, 0, name, password);

    cout << name << "�� " << id << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
    nCurrentAccountNum++;
}

void ATMachine::checkMoney() {
    int id;
    string password;

    cout << "------ ��ȸ ------" << endl;
    cout << "���¹�ȣ �Է�: ";
    cin >> id;
    cout << "��й�ȣ �Է�: ";
    cin >> password;

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                cout << "���� �ܾ�: " << balance << endl;
            } else {
                cout << "���� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
            }
            return;
        }
    }

    cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
}

void ATMachine::closeAccount() {
    int id;
    string password;

    cout << "------ ���� ------" << endl;
    cout << "���¹�ȣ �Է�: ";
    cin >> id;
    cout << "��й�ȣ �Է�: ";
    cin >> password;

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if (balance > 0) {
                    cout << "�ܾ��� �־� ������ �� �����ϴ�. �ܾ�: " << balance << endl;
                } else {
                    pAcctArray[i].close();

                    // �迭 ����
                    for (int j = i; j < nCurrentAccountNum - 1; j++) {
                        pAcctArray[j] = pAcctArray[j + 1];
                    }

                    nCurrentAccountNum--;
                    cout << id << " ���°� �����Ǿ����ϴ�. �����մϴ�." << endl;
                }
            } else {
                cout << "���� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
            }
            return;
        }
    }

    cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
}

void ATMachine::depositMoney() {
    int id, money;
    string password;

    cout << "------ �Ա� ------" << endl;
    cout << "���¹�ȣ �Է�: ";
    cin >> id;
    cout << "��й�ȣ �Է�: ";
    cin >> password;
    cout << "�Աݾ� �Է�: ";
    cin >> money;

    if (money <= 0) {
        cout << "�Աݾ��� 0���� Ŀ�� �մϴ�." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].deposit(id, password, money);
            if (result != AUTHENTIFICATION_FAIL) {
                nMachineBalance += money;
                cout << "�Ա� �Ϸ�" << endl;
                cout << "���� �ܾ�: " << result << endl;
            } else {
                cout << "���� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
            }
            return;
        }
    }

    cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
}

void ATMachine::widrawMoney() {
    int id, money;
    string password;

    cout << "------ ��� ------" << endl;
    cout << "���¹�ȣ �Է�: ";
    cin >> id;
    cout << "��й�ȣ �Է�: ";
    cin >> password;
    cout << "��ݾ� �Է�: ";
    cin >> money;

    if (money <= 0) {
        cout << "��ݾ��� 0���� Ŀ�� �մϴ�." << endl;
        return;
    }

    if (nMachineBalance < money) {
        cout << "ATM ����� �ܾ��� �����մϴ�." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if (balance < money) {
                    cout << "���� �ܾ��� �����մϴ�." << endl;
                } else {
                    int result = pAcctArray[i].widraw(id, password, money);
                    nMachineBalance -= money;
                    cout << "��� �Ϸ�" << endl;
                    cout << "���� �ܾ�: " << result << endl;
                }
            } else {
                cout << "���� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
            }
            return;
        }
    }

    cout << "�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
}