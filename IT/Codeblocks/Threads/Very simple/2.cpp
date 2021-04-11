

/// g++ -Wall -Wextra -Werror -g -pthread 1.cpp -o 1

#include <iostream>
#include <thread> 

void thread_func() {
  for (size_t i = 0; i < 10000; ++i) {
    std::cout << 1 << " ";
  }
  //std::cout << std::this_thread::get_id() << std::endl;
}

int main() {
  std::thread th(thread_func);
  //std::thread::id th_id = th.get_id();
  //th.join();
  for (size_t i = 0; i < 10000; ++i) {
    std::cout << 2 << " ";
  }
  th.join(); /// !!! necessary
  //std::cout << th_id << std::endl;
  return 0;	
}
