#include <iostream>

class A {
public:
  double d;
};

int main () {
  int a;
  unsigned b;
  char c;
  double y;
  A x;


  std::cout << "sizeof(int)      = " << sizeof(a) << "\n";
  std::cout << "sizeof(unsigned) = " << sizeof(b) << "\n";
  std::cout << "sizeof(char)     = " << sizeof(c) << "\n";
  std::cout << "sizeof(double)   = " << sizeof(y) << "\n";
  std::cout << "sizeof(A)        = " << sizeof(x) << "\n";

  std::cout << "\n";

  std::cout << "sizeof(int*)      = " << sizeof(&a) << "\n";
  std::cout << "sizeof(unsigned*) = " << sizeof(&b) << "\n";
  std::cout << "sizeof(char*)     = " << sizeof(&c) << "\n";
  std::cout << "sizeof(double*)   = " << sizeof(&y) << "\n";
  std::cout << "sizeof(A*)        = " << sizeof(&x) << "\n";

  return 0;
}
