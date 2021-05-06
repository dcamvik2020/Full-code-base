#include <iostream>
#include <thread>

void func() {
  std::cout << "Hi!\n";
}

int main() {
  std::thread T(func);
  for (unsigned i = 0; i < 10; ++i) {
    T.join();
    T = std::thread(func);
  }
  T.join();
  return 0;
}
