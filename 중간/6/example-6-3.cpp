#include <iostream>
#include <string>
using namespace std;

void star(int a = 5);
void msg(int id, string text = "");

int main() {
    star();
    star(10);

    msg(10);
    msg(10, "Hello");
    return 0;
}

void star(int a) {
    for (int i = 0; i < a; i++) {
        cout << '*';
    }
    cout << endl;
}

void msg(int id, string text) {
    cout << id << ' ' << text << endl;
}