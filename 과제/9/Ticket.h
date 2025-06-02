#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
    int nRow;
    int nCol;
    char charCheck;
    int nReservedID;
    int nPayAmount;
    int nPayMethod;
    int nShowtime;        // �󿵽ð� �ε��� (0~4)
    string customerName;  // ������ �̸�

public:
    Ticket() {
        nRow = 0;
        nCol = 0;
        charCheck = SEAT_EMPTY_MARK;
        nReservedID = 0;
        nPayAmount = 0;
        nPayMethod = 0;
        nShowtime = -1;
        customerName = "";
    }
    
    void setCheck(char check) { charCheck = check; }
    char getCheck() { return charCheck; }
    
    // �¼� ��ȣ ����
    void setSeat(int row, int col) { nRow = row; nCol = col; }
    
    // �¼� ���� ��ȣ ����
    void setReservedID(int reserved) { nReservedID = reserved; }
    int getReservedID() { return nReservedID; }
    
    void setPayAmount(int amount) { nPayAmount = amount; }
    int getPayAmount() { return nPayAmount; }
    void setPayMethod(int method) { nPayMethod = method; }
    
    // ���� �߰��� ��ɵ�
    void setShowtime(int showtime) { nShowtime = showtime; }
    int getShowtime() { return nShowtime; }
    void setCustomerName(string name) { customerName = name; }
    string getCustomerName() { return customerName; }
    int getRow() { return nRow; }
    int getCol() { return nCol; }
};

#endif
