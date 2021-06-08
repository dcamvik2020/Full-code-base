#include <iostream>

template <class T>
class Sum {
private:
  T a;
public:
  Sum(T a_0) : a(a_0) {}
  T operator() (T b) {return a+b;}
};

int main() {
  std::string a, b;
  std::cin >> a >> b;
  Sum<std::string> x(a);
  std::cout << x(b) << std::endl;
  return 0;
}
