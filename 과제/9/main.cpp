#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"
using namespace std;

int main() {
    TUKoreaTBox tBox;
    Screen * screen = NULL;
    bool bScreenMenu = true;
    int select = 0;
    
    tBox.Initialize(); // 3개의 스크린 객체 생성
    
    while (1) {
        if (bScreenMenu) {
            screen = tBox.selectMenu();
            bScreenMenu = false;
            if (!screen) return 0;
        }
        
        screen->showMovieMenu();
        cout << "메뉴를 선택하세요: ";
        cin >> select; cout << endl;
        
        switch (select) {
            case 1: // 영화 정보
                screen->showMovieInfo();
                break;
            case 2: // 좌석 현황
                screen->showSeatMap();
                break;
            case 3: // 좌석 예약
                screen->reserveTicket();
                break;
            case 4: // 티켓 결제
                screen->Payment();
                break;
            case 5: // 상영시간표 보기 (새로 추가)
                screen->showMovieSchedule();
                break;
            case 6: // 예약 조회 (새로 추가)
                {
                    int queryChoice;
                    cout << "-------------------------" << endl;
                    cout << "예약 조회 방법 선택" << endl;
                    cout << "-------------------------" << endl;
                    cout << "1. 예약번호로 조회" << endl;
                    cout << "2. 이름으로 조회" << endl;
                    cout << "선택 (1-2): ";
                    cin >> queryChoice;
                    
                    if (queryChoice == 1) {
                        screen->checkReservation();
                    } else if (queryChoice == 2) {
                        screen->checkReservationByName();
                    } else {
                        cout << "잘못된 선택입니다." << endl;
                    }
                }
                break;
            case 7: // 스크린 메인 메뉴
                bScreenMenu = true;
                break;
            default:
                cout << "잘못된 메뉴 선택입니다." << endl;
                break;
        }
    }
    
    return 0;
}
