#include  <iostream>

class A {
public:
//static int a = 1;         /// ERROR
  static const int b = 1;   /// OK
  static int c;             /// OK
  int d = 2;                /// OK
  int e;                    /// OK
  const int f = 4;          /// OK
//const int g;              /// ERROR 
};

class B {
public:
  class C {
  public:
    static const int x = 1;
  };
  int a = 1;
  int getC() const {return C::x;}
};

int main ()
{
  A a;
  B b;
  b.getC(); /// static const int ---> OK
  
//A * p1 = &a;
//A * p2 = &b; /// ERROR : can't covert
  
  int d;
//double * p = &d;   /// ERROR : can't convert

  return 0;
}
