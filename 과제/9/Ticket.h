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
    int nShowtime;        // 상영시간 인덱스 (0~4)
    string customerName;  // 예약자 이름

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
    
    // 좌석 번호 저장
    void setSeat(int row, int col) { nRow = row; nCol = col; }
    
    // 좌석 예약 번호 저장
    void setReservedID(int reserved) { nReservedID = reserved; }
    int getReservedID() { return nReservedID; }
    
    void setPayAmount(int amount) { nPayAmount = amount; }
    int getPayAmount() { return nPayAmount; }
    void setPayMethod(int method) { nPayMethod = method; }
    
    // 새로 추가된 기능들
    void setShowtime(int showtime) { nShowtime = showtime; }
    int getShowtime() { return nShowtime; }
    void setCustomerName(string name) { customerName = name; }
    string getCustomerName() { return customerName; }
    int getRow() { return nRow; }
    int getCol() { return nCol; }
};

#endif
