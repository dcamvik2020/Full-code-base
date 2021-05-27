#include <iostream>
#include <thread>

/// with lock_guard threads are exectued one by one in random order
/// while one thread is executing, other waits

///#include <mutex>
///std::mutex mtx;

void f1() {
  /// std::lock_guard<std::mutex> lg(mtx);
  for (int i = 0; i < 100; ++i) std::cout << "F";
}

void f2() {
  /// std::lock_guard<std::mutex> lg(mtx);
  for (int i = 0; i < 100; ++i) std::cout << "S";
}

int main () {
  std::thread t1(f1);
  std::thread t2(f2);
  t1.join();
  t2.join();
  std::cout << "\n";
  return 0;
}
