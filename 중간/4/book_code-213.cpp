#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    string tel;
public:
    Person();
    string getName() {
        return name;
    }
    string getTel() {
        return tel;
    }
    void set(string name, string tel);
};

Person::Person() {
    name = "";
    tel = "";
}

void Person::set(string name, string tel) {
    this -> name = name;
    this -> tel = tel;
}

int main(void) {
    Person *pArray = new Person[3];
    string name, tel;
    for (int i = 0; i < 3; i++) {
        cout << "��� " << i + 1 << ">> ";
        cin >> name >> tel;
        pArray[i].set(name, tel);
    }

    cout << "��� ����� �̸��� ";
    for (int i = 0; i < 3; i++) {
        cout << pArray[i].getName() << ' ';
    }
    cout << endl;

    cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>> ";
    cin >> name;

    for (int i = 0; i < 3; i++) {
        if (pArray[i].getName() == name) {
            cout << "��ȭ��ȣ�� " << pArray[i].getTel() << endl;
            break;
        }
    }
    
    return 0;
}