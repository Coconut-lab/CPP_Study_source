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