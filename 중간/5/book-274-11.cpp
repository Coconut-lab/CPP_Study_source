#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
    char *title;
    int price;
public:
    Book(const char* title, int price);
    Book(Book& b);
    ~Book();
    void set(char* title, int price);
    void show() {
        cout << title << ' ' << price << "원" << endl;
    }
};

Book::Book(const char* title, int price) {
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->price = price;
}
Book::~Book() {
    if (title)
        delete[] title;
}
void Book::set(char* title, int price) {
    if (this->title)
        delete[] this->title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->price = price;
}

Book::Book(Book& b) {
    title = b.title;
    price = b.price;
}

int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
    
    return 0;
}