#ifndef STATISTICS_H
#define STATISTICS_H

#include "Account.h"

class Statistics {
public:
    static int sum(Account* pArray, int size);
    static int average(Account* pArray, int size);
    static int min(Account* pArray, int size);
    static int max(Account* pArray, int size);
    static void sort(Account* pArray, int size);
};

#endif