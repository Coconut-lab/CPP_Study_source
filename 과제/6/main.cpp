#include <iostream>
#include "ATMachine.h"
using namespace std;

int main() {
    int select;
    // 계좌 수(100개), ATM 잔액 초기화, 관리자 암호
    ATMachine atm(100, 50000, "admin");

    while(1) {
        atm.displayMenu();
        cout << "메뉴를 선택하세요: ";
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
            case 6:
                atm.transfer(); // 계좌 이체 기능
                break;
            case 7:
                atm.requestSvc(); // 고객 센터 기능(비밀번호 변경)
                break;
            case 8:
                atm.managerMode(); // 고객 관리 기능
                break;
            case 9:
                cout << "이용해 주셔서 감사합니다." << endl;
                return 0;
            default:
                cout << "번호 확인 후 다시 입력하세요." << endl;
        }
    }

    return 0;
}