#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& stream) {
    cout << "암호? ";
    return stream;
}

int main() {
    string password;

    while (true) {
        cin >> prompt >> password;
        if (password == "C++") {
            cout << "login success!" << endl;
            break;
        } else {
            cout << "login failed! try again!!" << endl;
        }
    }
    return 0;
}