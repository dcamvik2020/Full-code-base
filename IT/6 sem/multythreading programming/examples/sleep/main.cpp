#include <iostream>
#include <chrono>
#include <thread>

/// if child sleeps more than master --> nothing is printed


void f() {
  std::chrono::milliseconds timespan(2000); // or whatever
  std::this_thread::sleep_for(timespan);
  std::cout << "child-thread has slept for " << std::chrono::milliseconds(timespan).count() << " milliseconds\n";
}

int main() {
  std::thread t(f);
  t.detach();
  
  
  std::chrono::milliseconds timespan(1000); // or whatever
  std::this_thread::sleep_for(timespan);
  std::cout << "master-thread has slept for " << std::chrono::milliseconds(timespan).count() << " milliseconds\n";

  return 0;
}
