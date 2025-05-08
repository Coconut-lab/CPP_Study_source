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
    cout << "1. 계좌 개설" << endl;
    cout << "2. 계좌 조회" << endl;
    cout << "3. 계좌 해지" << endl;
    cout << "4. 계좌 입금" << endl;
    cout << "5. 계좌 출금" << endl;
    cout << "9. 업무 종료" << endl;
    cout << "----------------------" << endl;
}

void ATMachine::createAccount() {
    if (nCurrentAccountNum >= nMaxAccountNum) {
        cout << "더 이상 계좌를 개설할 수 없습니다." << endl;
        return;
    }

    string name, password;

    cout << "------ 개설 ------" << endl;
    cout << "이름 입력: ";
    cin >> name;
    cout << "암호 입력: ";
    cin >> password;

    // 계좌번호 생성 (200 ~ 900번) 랜덤으로 번호 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(200, 900);
    int id = dis(gen);

    // 중복된 계좌번호가 있는지 확인
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            id = dis(gen); // 새로운 랜덤 번호 생성
            i = -1; // 루프 다시 시작
        }
    }

    // 계좌 생성
    pAcctArray[nCurrentAccountNum].create(id, 0, name, password);

    cout << name << "님 " << id << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
    nCurrentAccountNum++;
}

void ATMachine::checkMoney() {
    int id;
    string password;

    cout << "------ 조회 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                cout << "현재 잔액: " << balance << endl;
            } else {
                cout << "계좌 비밀번호가 일치하지 않습니다." << endl;
            }
            return;
        }
    }

    cout << "존재하지 않는 계좌번호입니다." << endl;
}

void ATMachine::closeAccount() {
    int id;
    string password;

    cout << "------ 해지 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if (balance > 0) {
                    cout << "잔액이 있어 해지할 수 없습니다. 잔액: " << balance << endl;
                } else {
                    pAcctArray[i].close();

                    // 배열 정리
                    for (int j = i; j < nCurrentAccountNum - 1; j++) {
                        pAcctArray[j] = pAcctArray[j + 1];
                    }

                    nCurrentAccountNum--;
                    cout << id << " 계좌가 해지되었습니다. 감사합니다." << endl;
                }
            } else {
                cout << "계좌 비밀번호가 일치하지 않습니다." << endl;
            }
            return;
        }
    }

    cout << "존재하지 않는 계좌번호입니다." << endl;
}

void ATMachine::depositMoney() {
    int id, money;
    string password;

    cout << "------ 입금 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "입금액 입력: ";
    cin >> money;

    if (money <= 0) {
        cout << "입금액은 0보다 커야 합니다." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].deposit(id, password, money);
            if (result != AUTHENTIFICATION_FAIL) {
                nMachineBalance += money;
                cout << "입금 완료" << endl;
                cout << "현재 잔액: " << result << endl;
            } else {
                cout << "계좌 비밀번호가 일치하지 않습니다." << endl;
            }
            return;
        }
    }

    cout << "존재하지 않는 계좌번호입니다." << endl;
}

void ATMachine::widrawMoney() {
    int id, money;
    string password;

    cout << "------ 출금 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "출금액 입력: ";
    cin >> money;

    if (money <= 0) {
        cout << "출금액은 0보다 커야 합니다." << endl;
        return;
    }

    if (nMachineBalance < money) {
        cout << "ATM 기기의 잔액이 부족합니다." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if (balance < money) {
                    cout << "계좌 잔액이 부족합니다." << endl;
                } else {
                    int result = pAcctArray[i].widraw(id, password, money);
                    nMachineBalance -= money;
                    cout << "출금 완료" << endl;
                    cout << "현재 잔액: " << result << endl;
                }
            } else {
                cout << "계좌 비밀번호가 일치하지 않습니다." << endl;
            }
            return;
        }
    }

    cout << "존재하지 않는 계좌번호입니다." << endl;
}