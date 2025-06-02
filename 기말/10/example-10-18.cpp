#include <iostream>
using namespace std;

int main() {
  int sum = 0;

  auto answer = [&sum](int x, int y) -> int {sum = x + y;} (2, 3);

  cout << "Sum: " << sum << endl;
}