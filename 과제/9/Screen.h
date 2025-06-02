#ifndef SCREEN_H
#define SCREEN_H

#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

class Screen {
protected:
    int nTicketPrice;           // Ƽ�� ����
    int nRowMax, nColMax;       // �¼� ��� �� �ִ� ��
    int nCurrentReservedId;     // �߱޵� ������ ���� ��ȣ
    Ticket ** pSeatArray;       // ��ũ�� �¼��� ���� Ƽ�� �迭
    string strMovieName;        // ��ũ�� ������ ��ȭ ����
    string showtimes[5];        // �󿵽ð�ǥ (5�� �ð���)

public:
    Screen(string name, int price, int row, int col);
    ~Screen();
    void showSeatMap();         // �¼� ���� ���� ������ ����
    virtual void showMovieMenu(); // ��ȭ ���� �޴�
    virtual void showMovieInfo() = 0; // ��ȭ �Ұ� ����
    
    void reserveTicket();       // �¼� �����ϱ�
    int getTicketPrice() { return nTicketPrice; }
    void Payment();             // �����ϱ�
    
    // ���� �߰��� ��ɵ�
    void showMovieSchedule();   // �󿵽ð�ǥ ����
    void checkReservation();    // �����ȣ�� ��ȸ
    void checkReservationByName(); // �̸����� ��ȸ
    string getShowtimeString(int index); // �󿵽ð� ���ڿ� ��ȯ
    
    int getRowMax() { return nRowMax; }
    int getColMax() { return nColMax; }
    Ticket** getTicketArray() { return pSeatArray; }
};

class CGVScreen : public Screen {
public:
    CGVScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

class LotteCinemaScreen : public Screen {
public:
    LotteCinemaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

class MegaboxScreen : public Screen {
public:
    MegaboxScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

#endif
