#include <iostream>

class A {
private:
  int x;
  double y;
public:
  //A(int _x) : x(_x) {};
  explicit A (double _y) : y(_y) {};
  void work () const {std::cout << "obj's work\n";}
  ~A() {}
};

void foo(A obj) {
  obj.work();
  std::cout << "object of class A is received\n";
}

int main() {
  A a(5), b(3.4); /// 2 objects of class A
  foo(a); foo(b); /// foo gets 2 ojects of A --> OK

  foo(5);         /// foo gets "int" --> implicit conversion failed
                  /// because of EXPLICIT keyword before constructor of A
  return 0;
}
