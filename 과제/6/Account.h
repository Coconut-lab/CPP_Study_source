#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using std::string;

#define AUTHENTIFICATION_FAIL -1 // 인증 실패 리턴값
#define AUTHENTIFICATION_SUCCESS 1 // 인증 성공 리턴값

class Account {
private:
    int nID;
    int nBalance;
    string strAccountName;
    string strPassword;

private:
    inline bool authenticate(int id, string passwd);

public:
    Account();
    void create(int id, int money, string name, string password); // 계좌 개설
    int check(int id, string password);
    int getAcctID() { return nID; }
    void close();
    int deposit(int id, string password, int money);
    int widraw(int id, string password, int money);
    
    // 추가 기능 1: 계좌 이체
    bool deposit(int id, int money);
    
    // 추가 기능 2: 비밀번호 변경
    bool updatePasswd(string oldPasswd, string newPasswd);
    
    // 추가 기능 3: 고객 관리
    int getBalance() { return nBalance; }
    string getAccountName() { return strAccountName; }
};

#endif