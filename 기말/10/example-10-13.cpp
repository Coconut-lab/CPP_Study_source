#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    cout << "정수 5개를 입력하라 >> ";
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}