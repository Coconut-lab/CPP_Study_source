#include "Account.h"

Account::Account() {
    nID = -1;
    nBalance = 0;
    strAccountName = "";
    strPassword = "";
}

bool Account::authenticate(int id, string passwd) {
    if (nID == id && strPassword == passwd) {
        return true;
    }
    return false;
}

void Account::create(int id, int money, string name, string password) {
    nID = id;
    nBalance = money;
    strAccountName = name;
    strPassword = password;
}

int Account::check(int id, string password) {
    if (authenticate(id, password)) {
        return nBalance;
    }
    return AUTHENTIFICATION_FAIL;
}

void Account::close() {
    if (nBalance == 0) {
        nID = -1;
        strAccountName = "";
        strPassword = "";
    }
}

int Account::deposit(int id, string password, int money) {
    if (authenticate(id, password)) {
        nBalance += money;
        return nBalance;
    }
    return AUTHENTIFICATION_FAIL;
}

int Account::widraw(int id, string password, int money) {
    if (authenticate(id, password)) {
        if (nBalance >= money) {
            nBalance -= money;
            return nBalance;
        }
    }
    return AUTHENTIFICATION_FAIL;
}

// 추가 기능 1: 계좌 이체용 입금 함수 (비밀번호 검증 없음)
bool Account::deposit(int id, int money) {
    if (nID == id) {
        nBalance += money;
        return true;
    }
    return false;
}

// 추가 기능 2: 비밀번호 변경
bool Account::updatePasswd(string oldPasswd, string newPasswd) {
    if (strPassword == oldPasswd) {
        strPassword = newPasswd;
        return true;
    }
    return false;
}