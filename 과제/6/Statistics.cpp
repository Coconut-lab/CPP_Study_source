#include "Statistics.h"

// 계좌 잔고 총합
int Statistics::sum(Account* pArray, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += pArray[i].getBalance();
    }
    return total;
}

// 계좌 잔고 평균
int Statistics::average(Account* pArray, int size) {
    if (size == 0) return 0;
    return sum(pArray, size) / size;
}

// 계좌 잔고 최소
int Statistics::min(Account* pArray, int size) {
    if (size == 0) return 0;

    int minVal = pArray[0].getBalance();
    
    for (int i = 1; i < size; i++) {
        if (pArray[i].getBalance() < minVal) {
            minVal = pArray[i].getBalance();
        }
    }
    return minVal;
}

// 계좌 잔고 최고
int Statistics::max(Account* pArray, int size) {
    if (size == 0) return 0;

    int maxVal = pArray[0].getBalance();
    
    for (int i = 1; i < size; i++) {
        if (pArray[i].getBalance() > maxVal) {
            maxVal = pArray[i].getBalance();
        }
    }
    return maxVal;
}

// 내림 차순 정렬 (잔액 기준)
void Statistics::sort(Account* pArray, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pArray[j].getBalance() < pArray[j + 1].getBalance()) {
                Account temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
            }
        }
    }
}