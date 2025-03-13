#include <iostream>
using namespace std;

int main() {
    cout << "너비를 입력하세요>> ";
    int width;
    cin >> width;   // 너비를 입력받는다.

    cout << "높이를 입력하세요>> ";
    int height;
    cin >> height;  // 높이를 입력받는다.

    int area = width * height;  // 넓이를 계산한다.
    cout << "면적은 " << area << endl;  // 넓이를 출력한다.
    return 0;
}