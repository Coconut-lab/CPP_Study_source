#include <iostream>
using namespace std;

// 잘못된 범위 입력 예외 클래스
class InvalidRangeException {
public:
    void print() {
        cout << "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요" << endl;
    }
};

// 입력 오류 예외 클래스  
class InputErrorException {
public:
    void print() {
        cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다" << endl;
    }
};

int main() {
    int n;
    
    while (true) {
        try {
            cout << "양수 입력 >> ";
            cin >> n;
            
            // cin이 실패한 경우 (문자 입력 등)
            if (cin.fail()) {
                cin.clear(); // 에러 플래그 초기화
                cin.ignore(1000, '\n'); // 입력 버퍼 비우기
                throw InputErrorException();
            }
            
            // 1~9 범위를 벗어난 경우
            if (n < 1 || n > 9) {
                throw InvalidRangeException();
            }
            
            // 정상적인 경우 구구단 출력
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
            break; // 프로그램 종료
        }
    }
    
    return 0;
}
