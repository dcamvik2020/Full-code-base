#include <iostream>
#include <thread>

int func (int x) {return x;}

int main() {
  std::thread T(func, 5);
  auto result = T.get();
  return 0;
}
