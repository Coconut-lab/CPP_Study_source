#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Screen.h"
#include "Pay.h"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
    strMovieName = name;
    nRowMax = row;
    nColMax = col;
    nTicketPrice = price;
    nCurrentReservedId = 0;
    
    // 상영시간표 초기화
    showtimes[0] = "09:00";
    showtimes[1] = "12:00";
    showtimes[2] = "15:00";
    showtimes[3] = "18:00";
    showtimes[4] = "21:00";
    
    pSeatArray = new Ticket*[nRowMax];
    for (int r = 0; r < nRowMax; r++) {
        pSeatArray[r] = new Ticket[nColMax];
    }
    
    for (int i = 0; i < nRowMax; i++) {
        for (int j = 0; j < nColMax; j++) {
            pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
        }
    }
}

Screen::~Screen() {
    for (int i = 0; i < nRowMax; i++) {
        delete[] pSeatArray[i];
    }
    delete[] pSeatArray;
}

void Screen::showMovieMenu() {
    cout << "-------------------------" << endl;
    cout << "메뉴 : " << strMovieName << endl;
    cout << "-------------------------" << endl;
    cout << "1. 영화 정보" << endl;
    cout << "2. 좌석 현황" << endl;
    cout << "3. 좌석 예약" << endl;
    cout << "4. 예매 결제" << endl;
    cout << "5. 상영시간표 보기" << endl;
    cout << "6. 예약 조회" << endl;
    cout << "7. 메인 메뉴 이동" << endl;
    cout << endl;
}

void Screen::showSeatMap() {
    int showtimeChoice;
    
    cout << "-------------------------" << endl;
    cout << "좌석 예약 현황 조회" << endl;
    cout << "-------------------------" << endl;
    cout << "상영시간을 선택하세요:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ". " << showtimes[i] << endl;
    }
    cout << "상영시간 선택 (1-5): ";
    cin >> showtimeChoice;
    
    if (showtimeChoice < 1 || showtimeChoice > 5) {
        cout << "잘못된 상영시간 선택입니다." << endl;
        return;
    }
    showtimeChoice--; // 배열 인덱스로 변환
    
    cout << "-------------------------" << endl;
    cout << "좌석 예약 현황 (" << showtimes[showtimeChoice] << ")" << endl;
    cout << "-------------------------" << endl;
    
    // 좌석 상태 표시 (선택된 상영시간에 해당하는 것만)
    cout << "   ";
    for (int j = 0; j < nColMax; j++) {
        cout << "[" << j+1 << "] ";
    }
    cout << endl;
    
    for (int i = 0; i < nRowMax; i++) {
        cout << "[" << i+1 << "] ";
        for (int j = 0; j < nColMax; j++) {
            // 선택된 상영시간에 해당하는 예약만 표시
            if (pSeatArray[i][j].getShowtime() == showtimeChoice && 
                (pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK || 
                 pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)) {
                cout << "[" << pSeatArray[i][j].getCheck() << "] ";
            } else {
                cout << "[" << SEAT_EMPTY_MARK << "] ";
            }
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
    cout << "범례: [" << SEAT_EMPTY_MARK << "] 빈좌석  [" 
         << SEAT_RESERVED_MARK << "] 예약완료  [" 
         << SEAT_COMPLETION_MARK << "] 결제완료" << endl;
    cout << "-------------------------" << endl;
}

void Screen::showMovieSchedule() {
    cout << "-------------------------" << endl;
    cout << "상영시간표 : " << strMovieName << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ". " << showtimes[i] << endl;
    }
    cout << "-------------------------" << endl;
}

string Screen::getShowtimeString(int index) {
    if (index >= 0 && index < 5) {
        return showtimes[index];
    }
    return "미정";
}

void Screen::reserveTicket() {
    int row, col, showtimeChoice;
    
    cout << "-------------------------" << endl;
    cout << "[ 좌석 예약 ]" << endl;
    cout << "-------------------------" << endl;
    
    // 상영시간 선택
    cout << "상영시간을 선택하세요:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ". " << showtimes[i] << endl;
    }
    cout << "상영시간 선택 (1-5): ";
    cin >> showtimeChoice;
    
    if (showtimeChoice < 1 || showtimeChoice > 5) {
        cout << "잘못된 상영시간 선택입니다." << endl;
        return;
    }
    showtimeChoice--; // 배열 인덱스로 변환
    
    cout << "선택된 상영시간: " << showtimes[showtimeChoice] << endl;
    cout << "-------------------------" << endl;
    
    cout << "좌석 행 번호 입력 [1-" << nRowMax << "]: ";
    cin >> row;
    cout << "좌석 열 번호 입력 [1-" << nColMax << "]: ";
    cin >> col;
    
    // 좌석 번호 유효성 검사
    if (row < 1 || row > nRowMax || col < 1 || col > nColMax) {
        cout << "행 [" << row << "]  열 [" << col << "] 번호가 잘못 입력되었습니다." << endl;
        return;
    }
    
    // 배열 인덱스는 0부터 시작하므로 -1
    row--; col--;
    
    // 이미 예약된 좌석인지 확인
    if (pSeatArray[row][col].getCheck() != SEAT_EMPTY_MARK) {
        cout << "행 [" << row+1 << "]  열 [" << col+1 << "] 이미 예약된 좌석입니다." << endl;
        return;
    }
    
    // 예약 처리
    nCurrentReservedId++;
    pSeatArray[row][col].setSeat(row+1, col+1);
    pSeatArray[row][col].setReservedID(nCurrentReservedId);
    pSeatArray[row][col].setShowtime(showtimeChoice);
    pSeatArray[row][col].setCheck(SEAT_RESERVED_MARK);
    
    cout << "상영시간: " << showtimes[showtimeChoice] << endl;
    cout << "행 [" << row+1 << "]  열 [" << col+1 << "] " << nCurrentReservedId << " 예약 번호로 접수되었습니다." << endl;
    cout << "예약이 완료되었습니다." << endl;
    cout << "-------------------------" << endl;
}

void Screen::Payment() {
    int reservedId, payMethod;
    
    cout << "-------------------------" << endl;
    cout << "[ 좌석 예약 결제 ]" << endl;
    cout << "-------------------------" << endl;
    cout << "예약 번호 입력 : ";
    cin >> reservedId;
    
    // 예약 번호로 좌석 찾기
    bool found = false;
    int targetRow = -1, targetCol = -1;
    
    for (int i = 0; i < nRowMax && !found; i++) {
        for (int j = 0; j < nColMax && !found; j++) {
            if (pSeatArray[i][j].getReservedID() == reservedId && 
                pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK) {
                targetRow = i;
                targetCol = j;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "예약 번호 " << reservedId << "를 찾을 수 없습니다." << endl;
        return;
    }
    
    cout << "-------------------------" << endl;
    cout << "결제 방식 선택" << endl;
    cout << "-------------------------" << endl;
    cout << "1. 모바일 결제" << endl;
    cout << "2. 무통장 입금" << endl;
    cout << "3. 카드 결제" << endl;
    cout << endl;
    cout << "결제 방식(1~3) : ";
    cin >> payMethod;
    
    Pay* payProcessor = NULL;
    string payMethodName;
    string userName, phoneNumber, accountNumber, cardNumber;
    
    switch (payMethod) {
        case MOBILE_PHONE_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "모바일 결제 정보 입력" << endl;
            cout << "-------------------------" << endl;
            cout << "이름 입력 : ";
            cin >> userName;
            cout << "핸드폰 번호 입력 : ";
            cin >> phoneNumber;
            payProcessor = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
            payMethodName = "모바일";
            break;
        case BANK_TRANSFER_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "무통장 입금 정보 입력" << endl;
            cout << "-------------------------" << endl;
            cout << "계좌번호 12자리 입력 : ";
            cin >> accountNumber;
            cout << "이름 입력 : ";
            cin >> userName;
            payProcessor = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
            payMethodName = "무통장";
            break;
        case CREDIT_CARD_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "카드 결제 정보 입력" << endl;
            cout << "-------------------------" << endl;
            cout << "카드번호 12자리 입력 : ";
            cin >> cardNumber;
            cout << "이름 입력 : ";
            cin >> userName;
            payProcessor = new CardPay(CREDIT_CARD_INTEREST_RATE);
            payMethodName = "카드";
            break;
        default:
            cout << "잘못된 결제 방식입니다." << endl;
            return;
    }
    
    int totalAmount = payProcessor->charge(nTicketPrice);
    
    cout << "-------------------------" << endl;
    cout << "이름 : " << userName << endl;
    
    if (payMethod == MOBILE_PHONE_PAYMENT) {
        cout << "핸드폰 번호 : " << phoneNumber << endl;
    } else if (payMethod == BANK_TRANSFER_PAYMENT) {
        cout << "계좌번호 : " << accountNumber << endl;
    } else if (payMethod == CREDIT_CARD_PAYMENT) {
        cout << "카드번호 : " << cardNumber << endl;
    }

    cout << "TUKOREA " << payMethodName << " 결제가 완료되었습니다. : " << totalAmount << endl;
    
    // 티켓 정보 업데이트 (예약자 이름도 저장)
    pSeatArray[targetRow][targetCol].setPayAmount(totalAmount);
    pSeatArray[targetRow][targetCol].setPayMethod(payMethod);
    pSeatArray[targetRow][targetCol].setCustomerName(userName);
    pSeatArray[targetRow][targetCol].setCheck(SEAT_COMPLETION_MARK);
    
    cout << "-------------------------" << endl;
    delete payProcessor;
}

void Screen::checkReservation() {
    int reservedId;
    
    cout << "-------------------------" << endl;
    cout << "[ 예약 조회 ]" << endl;
    cout << "-------------------------" << endl;
    cout << "예약 번호 입력 : ";
    cin >> reservedId;
    
    // 예약 번호로 좌석 찾기
    bool found = false;
    
    for (int i = 0; i < nRowMax && !found; i++) {
        for (int j = 0; j < nColMax && !found; j++) {
            if (pSeatArray[i][j].getReservedID() == reservedId && 
                (pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK || 
                 pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)) {
                
                cout << "-------------------------" << endl;
                cout << "예약 정보" << endl;
                cout << "-------------------------" << endl;
                cout << "예약 번호 : " << reservedId << endl;
                cout << "영화 제목 : " << strMovieName << endl;
                cout << "상영 시간 : " << getShowtimeString(pSeatArray[i][j].getShowtime()) << endl;
                cout << "좌석 : " << (i+1) << "행 " << (j+1) << "열" << endl;
                
                if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                    cout << "예약자 : " << pSeatArray[i][j].getCustomerName() << endl;
                    cout << "결제 금액 : " << pSeatArray[i][j].getPayAmount() << "원" << endl;
                    cout << "상태 : 결제완료" << endl;
                } else {
                    cout << "상태 : 예약완료 (결제대기)" << endl;
                }
                cout << "-------------------------" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "예약 번호 " << reservedId << "를 찾을 수 없습니다." << endl;
        cout << "-------------------------" << endl;
    }
}

void Screen::checkReservationByName() {
    string customerName;
    
    cout << "-------------------------" << endl;
    cout << "[ 이름으로 예약 조회 ]" << endl;
    cout << "-------------------------" << endl;
    cout << "예약자 이름 입력 : ";
    cin >> customerName;
    
    bool found = false;
    int count = 0;
    
    cout << "-------------------------" << endl;
    cout << customerName << "님의 예약 내역" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < nRowMax; i++) {
        for (int j = 0; j < nColMax; j++) {
            if (pSeatArray[i][j].getCustomerName() == customerName && 
                pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                
                count++;
                cout << count << ". 예약번호: " << pSeatArray[i][j].getReservedID() 
                     << " | 상영시간: " << getShowtimeString(pSeatArray[i][j].getShowtime())
                     << " | 좌석: " << (i+1) << "행 " << (j+1) << "열"
                     << " | 금액: " << pSeatArray[i][j].getPayAmount() << "원" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << customerName << "님의 예약 내역이 없습니다." << endl;
    }
    cout << "-------------------------" << endl;
}

// CGVScreen 구현 - 영화 정보를 실제 영화 내용으로 수정
void CGVScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "영화관 : CJ CGV 솔로 1관" << endl;
    cout << "출연진 : 유해진, 이제훈, 손현주, 최영준" << endl;
    cout << "줄거리 : 대한민국 국민 소주가 무너졌다! 1997년 IMF 외환위기, 독보적인 맛으로..." << endl;
    cout << "관람료 : " << nTicketPrice << "원" << endl;
    cout << "-------------------------" << endl;
}

// LotteCinemaScreen 구현  
void LotteCinemaScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "영화관 : 롯데시네마 영화 2관" << endl;
    cout << "출연진 : 크리스 샌더스, 마이아 켈알로하, 시드니 아구동" << endl;
    cout << "줄거리 : 보송보송한 파란 솜털, 호기심 가득한 큰 눈, 장난기 가득한 웃음을 가졌지만..! ..." << endl;
    cout << "관람료 : " << nTicketPrice << "원" << endl;
    cout << "-------------------------" << endl;
}

// MegaboxScreen 구현
void MegaboxScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "영화관 : 메가박스 영화 3관" << endl;
    cout << "출연진 : 톰 크루즈, 헤일리 앳웰, 빙 라메스, 사이먼 페그 ..." << endl;
    cout << "줄거리 : 디지털상의 모든 정보를 통제할 수 있는 사상 초유의 무기로 인해 전 세계 국가와 조직의..." << endl;
    cout << "관람료 : " << nTicketPrice << "원" << endl;
    cout << "-------------------------" << endl;
}
