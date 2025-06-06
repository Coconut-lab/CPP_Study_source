#include <iostream>
using namespace std;

// �߸��� ���� �Է� ���� Ŭ����
class InvalidRangeException {
public:
    void print() {
        cout << "�߸��� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���" << endl;
    }
};

// �Է� ���� ���� Ŭ����  
class InputErrorException {
public:
    void print() {
        cout << "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�" << endl;
    }
};

int main() {
    int n;
    
    while (true) {
        try {
            cout << "��� �Է� >> ";
            cin >> n;
            
            // cin�� ������ ��� (���� �Է� ��)
            if (cin.fail()) {
                cin.clear(); // ���� �÷��� �ʱ�ȭ
                cin.ignore(1000, '\n'); // �Է� ���� ����
                throw InputErrorException();
            }
            
            // 1~9 ������ ��� ���
            if (n < 1 || n > 9) {
                throw InvalidRangeException();
            }
            
            // �������� ��� ������ ���
            for (int i = 1; i <= 9; i++) {
                cout << n << "x" << i << "=" << n * i;
                if (i < 9) cout << " ";
            }
            cout << endl;
        }
        catch (InvalidRangeException &e) {
            e.print();
        }
        catch (InputErrorException &e) {
            e.print();
            break; // ���α׷� ����
        }
    }
    
    return 0;
}
