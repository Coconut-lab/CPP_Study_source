#include <iostream>
#include <string>
using namespace std;

void msg(int id) {
    cout << id << endl;
}

void msg(int id, string s="") {
    cout << id << ":" << s << endl;
}

int main() {
    msg(5, "Good Morning");
    // msg(6); // 함수 호출 모호. 컴파일 오류
    
    return 0;
}