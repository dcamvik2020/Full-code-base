#include <iostream>

int main() {
  int a[5][5];
  std::cout << "a[0][0] = " << a[0][0] << "\n";
  std::cout << "*a      = " << *a << "\n";
  std::cout << "*a[0]   = " << *a[0] << "\n";
  std::cout << "a       = " << a << "\n";

  std::cout << "a[0]    = " << a[0] << "\n";
  std::cout << "a+1     = " << a+1 << "\n";
  std::cout << "a[1]    = " << a[1] << "\n";
  std::cout << "a+2     = " << a+2 << "\n";
  
  std::cout << "a[2]    = " << a[2] << "\n";
  return 0;
}
