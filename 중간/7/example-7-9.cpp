#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this -> kick = kick;
        this -> punch = punch;
    }
    void show();
    bool operator! ();
};

void Power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

bool Power::operator! () {
    if (kick == 0 && punch == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Power a(0,0), b(5, 5);
    if (!a) {
        cout << "a is zero" << endl;
    } else {
        cout << "a is not zero" << endl;
    }

    if (!b) {
        cout << "b is zero" << endl;
    } else {
        cout << "b is not zero" << endl;
    }
}