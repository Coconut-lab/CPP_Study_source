#include "Pay.h"

// CardPay 구현
int CardPay::charge(int amount) {
    // 결제금액 = 티켓 가격 + 티켓 가격 * 카드수수료 비율
    return amount + (int)(amount * interest);
}

// BankTransfer 구현
int BankTransfer::charge(int amount) {
    // 결제금액 = 티켓 가격 + 티켓 가격 * 은행수수료 비율
    return amount + (int)(amount * interest);
}

// MobilePay 구현
int MobilePay::charge(int amount) {
    // 결제금액 = 티켓 가격 + 티켓 가격 * 모바일수수료 비율
    return amount + (int)(amount * interest);
}
