#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using std::string;

#define AUTHENTIFICATION_FAIL -1 // ���� ���� ����
#define AUTHENTIFICATION_SUCCESS 1 // ���� ���� ����

class Account {
private:
    int nID; // ���� ��ȣ (�ʱ� �� = -1) , ���� ������ �ʱⰪ���� ����
    int nBalance; // �ܰ� (�ʱ� �� = 0)
    string strAccountName; // �� ��
    string strPassword; // ���� ��й�ȣ

private:
    inline bool authenticate(int id, string passwd); // ���� ���� : true(1), ���� ���� : false(0)

public:
    Account();
    void create(int id, int money, string name, string password); // ���� ����
    int check(int id, string password); // return �� : nBalance (�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
    int getAcctID() { return nID; } // ���� ��ȣ �о����
    void close(); // �ܾ��� �����ϸ� ���� �Ұ�
    int deposit(int id, string password, int money); // return �� : nBalance (�����ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
    int widraw(int id, string password, int money); // return �� : nBalance (�����ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
};

#endif