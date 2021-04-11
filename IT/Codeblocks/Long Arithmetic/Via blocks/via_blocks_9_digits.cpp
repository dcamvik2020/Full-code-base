#include <iostream>
#include <vector>

#include "BigNumber.h"

int main() {
  std::string s;
  std::cin >> s;
  BigNumber x(s);
  std::cout << x << std::endl;
/*
  char op;
  std::string a, b, res;
  std::cin >> a >> op >> b;
  if (op == '+') {
    res = sum(a, b);
  } else if (op == '-') {
    res = sub(a, b);
  } else if (op == '*') {
    res = sum(a, b);
  }
 */
}
