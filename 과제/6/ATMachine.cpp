// ATMachine.cpp
#include "ATMachine.h"
#include "Statistics.h"
#include "CustomerSvc.h"
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
    cout << "6. 계좌 이체" << endl;
    cout << "7. 고객 센터" << endl;
    cout << "8. 고객 관리" << endl;
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
            id = dis(gen); // 새로운 계좌 번호 생성
            i = -1; // 처음 다시 확인
        }
    }

    pAcctArray[nCurrentAccountNum].create(id, 0, name, password);

    cout << name << "님 " << id << "번 계좌번호가 성공적으로 개설되었습니다. 감사합니다." << endl;
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
        cout << "ATM 기기의 잔고가 부족합니다." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int balance = pAcctArray[i].check(id, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if (balance < money) {
                    cout << "계좌 잔고가 부족합니다." << endl;
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

// 추가 기능 1: 계좌 이체
void ATMachine::transfer() {
    int sourceId, targetId, money;
    string password;

    cout << "------ 이체 ------" << endl;
    cout << "출금 계좌번호 입력: ";
    cin >> sourceId;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "입금 계좌번호 입력: ";
    cin >> targetId;
    cout << "이체금액 입력: ";
    cin >> money;

    if (money <= 0) {
        cout << "이체금액은 0보다 커야 합니다." << endl;
        return;
    }

    // 출금 계좌 찾기
    int sourceIndex = -1;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == sourceId) {
            sourceIndex = i;
            break;
        }
    }

    if (sourceIndex == -1) {
        cout << "출금 계좌가 존재하지 않습니다." << endl;
        return;
    }

    // 입금 계좌 찾기
    int targetIndex = -1;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == targetId) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        cout << "입금 계좌가 존재하지 않습니다." << endl;
        return;
    }

    // 출금 계좌에서 인출
    int balance = pAcctArray[sourceIndex].check(sourceId, password);
    if (balance == AUTHENTIFICATION_FAIL) {
        cout << "계좌 비밀번호가 일치하지 않습니다." << endl;
        return;
    }

    if (balance < money) {
        cout << "계좌 잔고가 부족합니다." << endl;
        return;
    }

    // 출금 처리
    pAcctArray[sourceIndex].widraw(sourceId, password, money);
    
    // 입금 처리
    bool result = pAcctArray[targetIndex].deposit(targetId, money);
    
    if (result) {
        cout << "이체가 성공적으로 완료되었습니다." << endl;
        cout << "현재 잔액: " << pAcctArray[sourceIndex].getBalance() << endl;
    } else {
        // 실패 시 출금 계좌에 다시 입금 (롤백)
        pAcctArray[sourceIndex].deposit(sourceId, password, money);
        cout << "이체 중 오류가 발생했습니다." << endl;
    }
}

// 추가 기능 2: 고객 센터 - 비밀번호 변경 요청
void ATMachine::requestSvc() {
    CustomerSvc svc(pAcctArray, nCurrentAccountNum);
    svc.updatePasswdReq();
}

// 추가 기능 3: 고객 관리 - 관리자 암호 확인
bool ATMachine::isManager(string password) {
    return strManagerPassword == password;
}

// 추가 기능 3: 고객 관리 - 통계 화면 처리
void ATMachine::displayReport() {
    cout << endl;
    cout << "---------- 관리 ----------" << endl;
    
    // ATM 현금 잔고 출력
    cout << "ATM 현재 잔고: " << nMachineBalance << "원" << endl;
    
    // 고객 잔고 총합
    int total = Statistics::sum(pAcctArray, nCurrentAccountNum);
    cout << "고객 잔고 총액: " << total << "원(" << nCurrentAccountNum << "명)" << endl;
    
    // 고객 잔고 평균
    int avg = Statistics::average(pAcctArray, nCurrentAccountNum);
    cout << "고객 잔고 평균: " << avg << "원" << endl;
    
    // 고객 잔고 최소
    int minBalance = Statistics::min(pAcctArray, nCurrentAccountNum);
    cout << "고객 잔고 최소: " << minBalance << "원" << endl;
    
    // 고객 잔고 최대
    int maxBalance = Statistics::max(pAcctArray, nCurrentAccountNum);
    cout << "고객 잔고 최대: " << maxBalance << "원" << endl;
    
    // 고객 계좌 현황 (잔액 내림차순 정렬)
    Statistics::sort(pAcctArray, nCurrentAccountNum);
    
    cout << "--- 고객 계좌 목록 ---" << endl;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        cout << (i+1) << ". " << pAcctArray[i].getAccountName() 
             << "\t" << pAcctArray[i].getAcctID() 
             << "\t" << pAcctArray[i].getBalance() << "원" << endl;
    }
}

// 추가 기능 3: 고객 관리
void ATMachine::managerMode() {
    string password;
    
    cout << "------ 관리 ------" << endl;
    cout << "관리자 비밀번호 입력: ";
    cin >> password;
    
    if (isManager(password)) {
        cout << "관리자입니다." << endl;
        displayReport();
    } else {
        cout << "비밀번호가 일치하지 않습니다." << endl;
    }
}