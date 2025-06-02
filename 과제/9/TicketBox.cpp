#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

TUKoreaTBox::TUKoreaTBox() {
    pCGVScreen = NULL;
    pLotteCinemaScreen = NULL;
    pMegaBoxScreen = NULL;
}

TUKoreaTBox::~TUKoreaTBox() {
    if (pCGVScreen) delete pCGVScreen;
    if (pLotteCinemaScreen) delete pLotteCinemaScreen;
    if (pMegaBoxScreen) delete pMegaBoxScreen;
}

// 스크린 객체 생성
void TUKoreaTBox::Initialize() {
    // Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
    pCGVScreen = new CGVScreen("소주전쟁", 15000, 8, 8);
    pLotteCinemaScreen = new LotteCinemaScreen("릴로 & 스티치", 12000, 10, 10);
    pMegaBoxScreen = new MegaboxScreen("미션 임파서블:파이널 레코닝", 20000, 8, 8);
}

Screen* TUKoreaTBox::selectMenu() {
    int choice;
    
    cout << "-------------------------" << endl;
    cout << "   상영관 메인 메뉴   " << endl;
    cout << "-------------------------" << endl;
    cout << "1. CJ CGV\t\t솔로 1관" << endl;
    cout << "2. 롯데시네마\t\t영화 2관" << endl;
    cout << "3. 메가박스\t\t영화 3관" << endl;
    cout << "9. 통계 관리" << endl;
    cout << endl;
    cout << "선택(1~3,9) 그외 종료 : ";
    cin >> choice;
    cout << endl;
    
    switch (choice) {
        case 1:
            return pCGVScreen;
        case 2:
            return pLotteCinemaScreen;
        case 3:
            return pMegaBoxScreen;
        case 9:
            // 통계 관리 실행
            Manage();
            return NULL; // 통계 관리 후 종료
        default:
            return NULL;
    }
}

void TUKoreaTBox::Manage() {
    string password;
    
    cout << "-------------------------" << endl;
    cout << "관리자 메뉴" << endl;
    cout << "-------------------------" << endl;
    cout << "관리자 비밀번호 입력 : ";
    cin >> password;
    
    if (password != TICKETBOX_MANAGER_PWD) {
        cout << "비밀번호가 틀렸습니다." << endl;
        return;
    }
    
    cout << endl;
    cout << "1. CJ CGV 상영관 결제금액 : " << Statistics::totalRevenue(pCGVScreen) << endl;
    cout << "2. 롯데시네마 상영관 결제금액 : " << Statistics::totalRevenue(pLotteCinemaScreen) << endl;
    cout << "3. 메가박스 상영관 결제금액 : " << Statistics::totalRevenue(pMegaBoxScreen) << endl;
    cout << "4. 전체 티켓 판매량 : " << 
        (Statistics::totalSalesCount(pCGVScreen) + 
         Statistics::totalSalesCount(pLotteCinemaScreen) + 
         Statistics::totalSalesCount(pMegaBoxScreen)) << endl;
}
