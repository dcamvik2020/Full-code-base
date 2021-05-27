#include <iostream>
#include "lock_free_stack.h"

#include <vector>
#include <thread>

// using lock_free_stack<T> = LFS<T>;

//void debug(LFS & stack, std::vector<std::thread> & T, const unsigned N);



int main(int argc, char * argv[]) {
  if (argc < 2) {
    std::cout << "Too few arguments.\n";
    return 0;
  }

  const unsigned N = atol(argv[1]);
  LFS<int> stack; /// default constructor --> empty stack
  std::vector<std::thread> T(N); /// all threads in
  //debug(stack, T, N);
  return 0;
}


/*
void debug(LFS & stack, std::vector<std::thread> & T, const unsigned N) {
  for (unsigned i = 0; i < N; ++i) {
    T.push_back(std::thread(LFS::push, std::ref(stack), i));
  }
  for (unsigned i = 0; i < N; ++i) {
    T[i].join();
  }
}
*/
