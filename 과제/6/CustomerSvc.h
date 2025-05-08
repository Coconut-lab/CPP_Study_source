#ifndef CUSTOMERSVC_H
#define CUSTOMERSVC_H

#include "Account.h"

class CustomerSvc {
private:
    Account* pAcctArray;
    int nMaxAccountNum;

public:
    CustomerSvc(Account* acctArray, int nMaxAccountNum);
    void updatePasswdReq();
};

#endif