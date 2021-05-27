
#include <iostream>

#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <typeinfo>

#include "tools.h"
#include "ttas_mutex.h"
#include "tas_mutex.h"
#include "ticket_lock.h"


std::mutex    mtx;
TAS_mutex     TAS;
TTAS_mutex    TTAS;
ticket_lock   ticket;


template <typename T>
void MutexTest(T& locker, unsigned iter_number) {
  locker.lock();
  for (long long volatile i = 0; i < iter_number; i++) {}
  locker.unlock();
}



template <typename T>
void WorkMutexTest(T& my_mutex, unsigned threads_number, unsigned iter_number) {
  std::vector<std::thread> threads;
  {
    std::cout << std::string(typeid(my_mutex).name()) + " Test:\n";
    Timer timer;
    for (unsigned i = 0; i < threads_number; i++) {
      threads.push_back(std::thread(MutexTest<T> , std::ref(my_mutex), std::cref(iter_number)));
    }

    for (unsigned i = 0; i < threads_number; ++i) {
      threads[i].join();
    }
    std::cout << "It took (seconds) : ";
    std::cout << timer.elapsed() << "\n";
  }
}


void GeneralTest(unsigned thread_number, unsigned iter_number) {
  WorkMutexTest <std::mutex>    (mtx, thread_number, iter_number);
  WorkMutexTest <TAS_mutex>     (TAS, thread_number, iter_number);
  WorkMutexTest <TTAS_mutex>    (TTAS, thread_number, iter_number);
  WorkMutexTest <ticket_lock>   (ticket, thread_number, iter_number);
}


int main() {
  size_t thread_number = 10;
  long long iter_number = 1'000'000'000;
  GeneralTest(thread_number, iter_number);
  return 0;
}
