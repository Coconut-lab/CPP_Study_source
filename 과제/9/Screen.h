#ifndef SCREEN_H
#define SCREEN_H

#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

class Screen {
protected:
    int nTicketPrice;           // 티켓 가격
    int nRowMax, nColMax;       // 좌석 행과 열 최대 값
    int nCurrentReservedId;     // 발급된 마지막 예약 번호
    Ticket ** pSeatArray;       // 스크린 좌석에 대한 티켓 배열
    string strMovieName;        // 스크린 상영중인 영화 제목
    string showtimes[5];        // 상영시간표 (5개 시간대)

public:
    Screen(string name, int price, int row, int col);
    ~Screen();
    void showSeatMap();         // 좌석 예약 여부 맵으로 보기
    virtual void showMovieMenu(); // 영화 예매 메뉴
    virtual void showMovieInfo() = 0; // 영화 소개 정보
    
    void reserveTicket();       // 좌석 예약하기
    int getTicketPrice() { return nTicketPrice; }
    void Payment();             // 결제하기
    
    // 새로 추가된 기능들
    void showMovieSchedule();   // 상영시간표 보기
    void checkReservation();    // 예약번호로 조회
    void checkReservationByName(); // 이름으로 조회
    string getShowtimeString(int index); // 상영시간 문자열 반환
    
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
