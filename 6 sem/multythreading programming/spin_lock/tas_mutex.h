#pragma once

#include <atomic>
#include <cassert>

class TAS_mutex {
  std::atomic<unsigned int> m_spin = {0};
public:
  TAS_mutex() {}

  ~TAS_mutex() {
    assert(m_spin.load() == 0);
  }

  void lock() {
    unsigned int expected = 0;
    do {
      expected = 0;
    } while (!m_spin.compare_exchange_weak(expected, 1));
  }

  void unlock() {
    m_spin.store(0);
  }
};

