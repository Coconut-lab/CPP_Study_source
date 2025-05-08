#include "CustomerSvc.h"
#include <iostream>
using namespace std;

CustomerSvc::CustomerSvc(Account* acctArray, int nMaxAccountNum) {
    pAcctArray = acctArray;
    this->nMaxAccountNum = nMaxAccountNum;
}

void CustomerSvc::updatePasswdReq() {
    int id;
    string oldPasswd, newPasswd;

    cout << "------ 비밀번호 변경 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "기존비밀 입력: ";
    cin >> oldPasswd;
    cout << "신규비밀 입력: ";
    cin >> newPasswd;

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            bool result = pAcctArray[i].updatePasswd(oldPasswd, newPasswd);
            
            if (result) {
                cout << "비밀번호를 수정하였습니다." << endl;
            } else {
                cout << "비밀번호가 일치하지 않습니다." << endl;
            }
            return;
        }
    }

    cout << "존재하지 않는 계좌번호입니다." << endl;
}