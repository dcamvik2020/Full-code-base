#include <iostream>

class Factorial {
public:
  long operator() (int n) {
    long res = 1;
    for ( ; n > 1; res *= n--);
    return res;
  }
};

int main() {
  int n;
  std::cin >> n;
  Factorial f;
  std::cout << f(n) << std::endl;
  return 0;
}
