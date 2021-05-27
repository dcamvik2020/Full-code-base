#pragma once

#include <atomic>


class ticket_lock {
  std::atomic<unsigned> now_serving = { 0 };
  std::atomic<unsigned> next_ticket = { 0 };
public:
  void lock() {
    const auto ticket = next_ticket.fetch_add(1);
    while (now_serving.load() != ticket);
  }

  void unlock() {
    const auto successor = now_serving.load() + 1;
    now_serving.store(successor);
  }
};

