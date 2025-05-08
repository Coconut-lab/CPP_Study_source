#ifndef ATMACHINE_H
#define ATMACHINE_H
#include <string>
#include "Account.h"
using std::string;

#define NEGATIVE_ATM_BALANCE -10 // ATM 잔고 부족

class ATMachine {
private:
    Account * pAcctArray;
    int nMachineBalance;
    int nMaxAccountNum;
    int nCurrentAccountNum;
    string strManagerPassword;

private:
    // 추가 기능 3: 고객 관리
    bool isManager(string password);
    void displayReport();

public:
    ATMachine(int size, int balance, string password);
    ~ATMachine();
    void displayMenu();
    void createAccount();
    void checkMoney();
    void closeAccount();
    void depositMoney();
    void widrawMoney();
    
    // 추가 기능 1: 계좌 이체
    void transfer();
    
    // 추가 기능 2: 고객 센터
    void requestSvc();
    
    // 추가 기능 3: 고객 관리
    void managerMode();
};

#endif