#pragma once

#include <chrono>
#include <atomic>
#include <cmath>
#include <cassert>
#include <immintrin.h>
#include <thread>

class TTAS_mutex {
  std::atomic<unsigned int> m_spin = {0};
public:
  TTAS_mutex() {}

  ~TTAS_mutex() {
    assert(m_spin.load() == 0);
  }

  void lock() {
    unsigned int expected = 0;
    do {
      unsigned exponent = 0;
      while (m_spin.load()) {
        _mm_pause(); // <==> __asm volatile ("pause" ::: "memory");
        //exponential backoff
        int time = 100 * pow(2, exponent) + rand() % 25;
        exponent++;
        std::this_thread::sleep_for(std::chrono::microseconds(time));
      }
      expected = 0;
    } while (!m_spin.compare_exchange_weak(expected, 1));
  }

  void unlock() {
    m_spin.store(0);
  }
};


