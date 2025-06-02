#include "Pay.h"

// CardPay ����
int CardPay::charge(int amount) {
    // �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * ī������� ����
    return amount + (int)(amount * interest);
}

// BankTransfer ����
int BankTransfer::charge(int amount) {
    // �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * ��������� ����
    return amount + (int)(amount * interest);
}

// MobilePay ����
int MobilePay::charge(int amount) {
    // �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * ����ϼ����� ����
    return amount + (int)(amount * interest);
}
