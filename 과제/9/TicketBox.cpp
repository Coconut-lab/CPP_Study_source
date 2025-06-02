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

// ��ũ�� ��ü ����
void TUKoreaTBox::Initialize() {
    // Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
    pCGVScreen = new CGVScreen("��������", 15000, 8, 8);
    pLotteCinemaScreen = new LotteCinemaScreen("���� & ��Ƽġ", 12000, 10, 10);
    pMegaBoxScreen = new MegaboxScreen("�̼� ���ļ���:���̳� ���ڴ�", 20000, 8, 8);
}

Screen* TUKoreaTBox::selectMenu() {
    int choice;
    
    cout << "-------------------------" << endl;
    cout << "   �󿵰� ���� �޴�   " << endl;
    cout << "-------------------------" << endl;
    cout << "1. CJ CGV\t\t�ַ� 1��" << endl;
    cout << "2. �Ե��ó׸�\t\t��ȭ 2��" << endl;
    cout << "3. �ް��ڽ�\t\t��ȭ 3��" << endl;
    cout << "9. ��� ����" << endl;
    cout << endl;
    cout << "����(1~3,9) �׿� ���� : ";
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
            // ��� ���� ����
            Manage();
            return NULL; // ��� ���� �� ����
        default:
            return NULL;
    }
}

void TUKoreaTBox::Manage() {
    string password;
    
    cout << "-------------------------" << endl;
    cout << "������ �޴�" << endl;
    cout << "-------------------------" << endl;
    cout << "������ ��й�ȣ �Է� : ";
    cin >> password;
    
    if (password != TICKETBOX_MANAGER_PWD) {
        cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
        return;
    }
    
    cout << endl;
    cout << "1. CJ CGV �󿵰� �����ݾ� : " << Statistics::totalRevenue(pCGVScreen) << endl;
    cout << "2. �Ե��ó׸� �󿵰� �����ݾ� : " << Statistics::totalRevenue(pLotteCinemaScreen) << endl;
    cout << "3. �ް��ڽ� �󿵰� �����ݾ� : " << Statistics::totalRevenue(pMegaBoxScreen) << endl;
    cout << "4. ��ü Ƽ�� �Ǹŷ� : " << 
        (Statistics::totalSalesCount(pCGVScreen) + 
         Statistics::totalSalesCount(pLotteCinemaScreen) + 
         Statistics::totalSalesCount(pMegaBoxScreen)) << endl;
}
