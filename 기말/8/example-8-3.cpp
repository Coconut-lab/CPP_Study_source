#include <iostream>
#include <string>
using namespace std;

class TV {
    int size;
public:
    TV() {
        size = 20;
    }
    TV(int size) {
        this -> size = size;
    }
    int getSize() {
        return size;
    }
};

class WideTV : public TV {
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size) {
        this -> videoIn = videoIn;
    }
    bool getVideoIn() {
        return videoIn;
    }
};

class SmartTV : public WideTV {
    string ipAddr;
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true) {
        this -> ipAddr = ipAddr;
    }
    string getIPAddr() {
        return ipAddr;
    }
};

int main() {
    SmartTV htv("192.0.0.1", 32);
    cout << "Size: " << htv.getSize() << endl;
    cout << "VideoIn: " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP: " << htv.getIPAddr() << endl;
}