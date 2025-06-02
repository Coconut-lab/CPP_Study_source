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
    
    // �󿵽ð�ǥ �ʱ�ȭ
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
    cout << "�޴� : " << strMovieName << endl;
    cout << "-------------------------" << endl;
    cout << "1. ��ȭ ����" << endl;
    cout << "2. �¼� ��Ȳ" << endl;
    cout << "3. �¼� ����" << endl;
    cout << "4. ���� ����" << endl;
    cout << "5. �󿵽ð�ǥ ����" << endl;
    cout << "6. ���� ��ȸ" << endl;
    cout << "7. ���� �޴� �̵�" << endl;
    cout << endl;
}

void Screen::showSeatMap() {
    int showtimeChoice;
    
    cout << "-------------------------" << endl;
    cout << "�¼� ���� ��Ȳ ��ȸ" << endl;
    cout << "-------------------------" << endl;
    cout << "�󿵽ð��� �����ϼ���:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ". " << showtimes[i] << endl;
    }
    cout << "�󿵽ð� ���� (1-5): ";
    cin >> showtimeChoice;
    
    if (showtimeChoice < 1 || showtimeChoice > 5) {
        cout << "�߸��� �󿵽ð� �����Դϴ�." << endl;
        return;
    }
    showtimeChoice--; // �迭 �ε����� ��ȯ
    
    cout << "-------------------------" << endl;
    cout << "�¼� ���� ��Ȳ (" << showtimes[showtimeChoice] << ")" << endl;
    cout << "-------------------------" << endl;
    
    // �¼� ���� ǥ�� (���õ� �󿵽ð��� �ش��ϴ� �͸�)
    cout << "   ";
    for (int j = 0; j < nColMax; j++) {
        cout << "[" << j+1 << "] ";
    }
    cout << endl;
    
    for (int i = 0; i < nRowMax; i++) {
        cout << "[" << i+1 << "] ";
        for (int j = 0; j < nColMax; j++) {
            // ���õ� �󿵽ð��� �ش��ϴ� ���ุ ǥ��
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
    cout << "����: [" << SEAT_EMPTY_MARK << "] ���¼�  [" 
         << SEAT_RESERVED_MARK << "] ����Ϸ�  [" 
         << SEAT_COMPLETION_MARK << "] �����Ϸ�" << endl;
    cout << "-------------------------" << endl;
}

void Screen::showMovieSchedule() {
    cout << "-------------------------" << endl;
    cout << "�󿵽ð�ǥ : " << strMovieName << endl;
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
    return "����";
}

void Screen::reserveTicket() {
    int row, col, showtimeChoice;
    
    cout << "-------------------------" << endl;
    cout << "[ �¼� ���� ]" << endl;
    cout << "-------------------------" << endl;
    
    // �󿵽ð� ����
    cout << "�󿵽ð��� �����ϼ���:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ". " << showtimes[i] << endl;
    }
    cout << "�󿵽ð� ���� (1-5): ";
    cin >> showtimeChoice;
    
    if (showtimeChoice < 1 || showtimeChoice > 5) {
        cout << "�߸��� �󿵽ð� �����Դϴ�." << endl;
        return;
    }
    showtimeChoice--; // �迭 �ε����� ��ȯ
    
    cout << "���õ� �󿵽ð�: " << showtimes[showtimeChoice] << endl;
    cout << "-------------------------" << endl;
    
    cout << "�¼� �� ��ȣ �Է� [1-" << nRowMax << "]: ";
    cin >> row;
    cout << "�¼� �� ��ȣ �Է� [1-" << nColMax << "]: ";
    cin >> col;
    
    // �¼� ��ȣ ��ȿ�� �˻�
    if (row < 1 || row > nRowMax || col < 1 || col > nColMax) {
        cout << "�� [" << row << "]  �� [" << col << "] ��ȣ�� �߸� �ԷµǾ����ϴ�." << endl;
        return;
    }
    
    // �迭 �ε����� 0���� �����ϹǷ� -1
    row--; col--;
    
    // �̹� ����� �¼����� Ȯ��
    if (pSeatArray[row][col].getCheck() != SEAT_EMPTY_MARK) {
        cout << "�� [" << row+1 << "]  �� [" << col+1 << "] �̹� ����� �¼��Դϴ�." << endl;
        return;
    }
    
    // ���� ó��
    nCurrentReservedId++;
    pSeatArray[row][col].setSeat(row+1, col+1);
    pSeatArray[row][col].setReservedID(nCurrentReservedId);
    pSeatArray[row][col].setShowtime(showtimeChoice);
    pSeatArray[row][col].setCheck(SEAT_RESERVED_MARK);
    
    cout << "�󿵽ð�: " << showtimes[showtimeChoice] << endl;
    cout << "�� [" << row+1 << "]  �� [" << col+1 << "] " << nCurrentReservedId << " ���� ��ȣ�� �����Ǿ����ϴ�." << endl;
    cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
    cout << "-------------------------" << endl;
}

void Screen::Payment() {
    int reservedId, payMethod;
    
    cout << "-------------------------" << endl;
    cout << "[ �¼� ���� ���� ]" << endl;
    cout << "-------------------------" << endl;
    cout << "���� ��ȣ �Է� : ";
    cin >> reservedId;
    
    // ���� ��ȣ�� �¼� ã��
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
        cout << "���� ��ȣ " << reservedId << "�� ã�� �� �����ϴ�." << endl;
        return;
    }
    
    cout << "-------------------------" << endl;
    cout << "���� ��� ����" << endl;
    cout << "-------------------------" << endl;
    cout << "1. ����� ����" << endl;
    cout << "2. ������ �Ա�" << endl;
    cout << "3. ī�� ����" << endl;
    cout << endl;
    cout << "���� ���(1~3) : ";
    cin >> payMethod;
    
    Pay* payProcessor = NULL;
    string payMethodName;
    string userName, phoneNumber, accountNumber, cardNumber;
    
    switch (payMethod) {
        case MOBILE_PHONE_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "����� ���� ���� �Է�" << endl;
            cout << "-------------------------" << endl;
            cout << "�̸� �Է� : ";
            cin >> userName;
            cout << "�ڵ��� ��ȣ �Է� : ";
            cin >> phoneNumber;
            payProcessor = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
            payMethodName = "�����";
            break;
        case BANK_TRANSFER_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "������ �Ա� ���� �Է�" << endl;
            cout << "-------------------------" << endl;
            cout << "���¹�ȣ 12�ڸ� �Է� : ";
            cin >> accountNumber;
            cout << "�̸� �Է� : ";
            cin >> userName;
            payProcessor = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
            payMethodName = "������";
            break;
        case CREDIT_CARD_PAYMENT:
            cout << "-------------------------" << endl;
            cout << "ī�� ���� ���� �Է�" << endl;
            cout << "-------------------------" << endl;
            cout << "ī���ȣ 12�ڸ� �Է� : ";
            cin >> cardNumber;
            cout << "�̸� �Է� : ";
            cin >> userName;
            payProcessor = new CardPay(CREDIT_CARD_INTEREST_RATE);
            payMethodName = "ī��";
            break;
        default:
            cout << "�߸��� ���� ����Դϴ�." << endl;
            return;
    }
    
    int totalAmount = payProcessor->charge(nTicketPrice);
    
    cout << "-------------------------" << endl;
    cout << "�̸� : " << userName << endl;
    
    if (payMethod == MOBILE_PHONE_PAYMENT) {
        cout << "�ڵ��� ��ȣ : " << phoneNumber << endl;
    } else if (payMethod == BANK_TRANSFER_PAYMENT) {
        cout << "���¹�ȣ : " << accountNumber << endl;
    } else if (payMethod == CREDIT_CARD_PAYMENT) {
        cout << "ī���ȣ : " << cardNumber << endl;
    }

    cout << "TUKOREA " << payMethodName << " ������ �Ϸ�Ǿ����ϴ�. : " << totalAmount << endl;
    
    // Ƽ�� ���� ������Ʈ (������ �̸��� ����)
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
    cout << "[ ���� ��ȸ ]" << endl;
    cout << "-------------------------" << endl;
    cout << "���� ��ȣ �Է� : ";
    cin >> reservedId;
    
    // ���� ��ȣ�� �¼� ã��
    bool found = false;
    
    for (int i = 0; i < nRowMax && !found; i++) {
        for (int j = 0; j < nColMax && !found; j++) {
            if (pSeatArray[i][j].getReservedID() == reservedId && 
                (pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK || 
                 pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)) {
                
                cout << "-------------------------" << endl;
                cout << "���� ����" << endl;
                cout << "-------------------------" << endl;
                cout << "���� ��ȣ : " << reservedId << endl;
                cout << "��ȭ ���� : " << strMovieName << endl;
                cout << "�� �ð� : " << getShowtimeString(pSeatArray[i][j].getShowtime()) << endl;
                cout << "�¼� : " << (i+1) << "�� " << (j+1) << "��" << endl;
                
                if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                    cout << "������ : " << pSeatArray[i][j].getCustomerName() << endl;
                    cout << "���� �ݾ� : " << pSeatArray[i][j].getPayAmount() << "��" << endl;
                    cout << "���� : �����Ϸ�" << endl;
                } else {
                    cout << "���� : ����Ϸ� (�������)" << endl;
                }
                cout << "-------------------------" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "���� ��ȣ " << reservedId << "�� ã�� �� �����ϴ�." << endl;
        cout << "-------------------------" << endl;
    }
}

void Screen::checkReservationByName() {
    string customerName;
    
    cout << "-------------------------" << endl;
    cout << "[ �̸����� ���� ��ȸ ]" << endl;
    cout << "-------------------------" << endl;
    cout << "������ �̸� �Է� : ";
    cin >> customerName;
    
    bool found = false;
    int count = 0;
    
    cout << "-------------------------" << endl;
    cout << customerName << "���� ���� ����" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < nRowMax; i++) {
        for (int j = 0; j < nColMax; j++) {
            if (pSeatArray[i][j].getCustomerName() == customerName && 
                pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                
                count++;
                cout << count << ". �����ȣ: " << pSeatArray[i][j].getReservedID() 
                     << " | �󿵽ð�: " << getShowtimeString(pSeatArray[i][j].getShowtime())
                     << " | �¼�: " << (i+1) << "�� " << (j+1) << "��"
                     << " | �ݾ�: " << pSeatArray[i][j].getPayAmount() << "��" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << customerName << "���� ���� ������ �����ϴ�." << endl;
    }
    cout << "-------------------------" << endl;
}

// CGVScreen ���� - ��ȭ ������ ���� ��ȭ �������� ����
void CGVScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "��ȭ�� : CJ CGV �ַ� 1��" << endl;
    cout << "�⿬�� : ������, ������, ������, �ֿ���" << endl;
    cout << "�ٰŸ� : ���ѹα� ���� ���ְ� ��������! 1997�� IMF ��ȯ����, �������� ������..." << endl;
    cout << "������ : " << nTicketPrice << "��" << endl;
    cout << "-------------------------" << endl;
}

// LotteCinemaScreen ����  
void LotteCinemaScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "��ȭ�� : �Ե��ó׸� ��ȭ 2��" << endl;
    cout << "�⿬�� : ũ���� ������, ���̾� �̾˷���, �õ�� �Ʊ���" << endl;
    cout << "�ٰŸ� : ���ۺ����� �Ķ� ����, ȣ��� ������ ū ��, �峭�� ������ ������ ��������..! ..." << endl;
    cout << "������ : " << nTicketPrice << "��" << endl;
    cout << "-------------------------" << endl;
}

// MegaboxScreen ����
void MegaboxScreen::showMovieInfo() {
    cout << "-------------------------" << endl;
    cout << "     [ "<< strMovieName << " ]     " << endl;
    cout << "-------------------------" << endl;
    cout << "��ȭ�� : �ް��ڽ� ��ȭ 3��" << endl;
    cout << "�⿬�� : �� ũ����, ���ϸ� ����, �� ��޽�, ���̸� ��� ..." << endl;
    cout << "�ٰŸ� : �����л��� ��� ������ ������ �� �ִ� ��� ������ ����� ���� �� ���� ������ ������..." << endl;
    cout << "������ : " << nTicketPrice << "��" << endl;
    cout << "-------------------------" << endl;
}
