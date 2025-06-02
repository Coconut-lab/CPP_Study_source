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
    
    tBox.Initialize(); // 3���� ��ũ�� ��ü ����
    
    while (1) {
        if (bScreenMenu) {
            screen = tBox.selectMenu();
            bScreenMenu = false;
            if (!screen) return 0;
        }
        
        screen->showMovieMenu();
        cout << "�޴��� �����ϼ���: ";
        cin >> select; cout << endl;
        
        switch (select) {
            case 1: // ��ȭ ����
                screen->showMovieInfo();
                break;
            case 2: // �¼� ��Ȳ
                screen->showSeatMap();
                break;
            case 3: // �¼� ����
                screen->reserveTicket();
                break;
            case 4: // Ƽ�� ����
                screen->Payment();
                break;
            case 5: // �󿵽ð�ǥ ���� (���� �߰�)
                screen->showMovieSchedule();
                break;
            case 6: // ���� ��ȸ (���� �߰�)
                {
                    int queryChoice;
                    cout << "-------------------------" << endl;
                    cout << "���� ��ȸ ��� ����" << endl;
                    cout << "-------------------------" << endl;
                    cout << "1. �����ȣ�� ��ȸ" << endl;
                    cout << "2. �̸����� ��ȸ" << endl;
                    cout << "���� (1-2): ";
                    cin >> queryChoice;
                    
                    if (queryChoice == 1) {
                        screen->checkReservation();
                    } else if (queryChoice == 2) {
                        screen->checkReservationByName();
                    } else {
                        cout << "�߸��� �����Դϴ�." << endl;
                    }
                }
                break;
            case 7: // ��ũ�� ���� �޴�
                bScreenMenu = true;
                break;
            default:
                cout << "�߸��� �޴� �����Դϴ�." << endl;
                break;
        }
    }
    
    return 0;
}
