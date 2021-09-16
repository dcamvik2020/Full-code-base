#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

template <typename T>
class PriorityQueue {
private:
  unsigned heapsize;
  std::vector<T> tasks;
  
public:
  PriorityQueue() {}
  ~PriorityQueue() {}
  
  void insert (const T & task); /// TODO
  T maximum () const; /// TODO
  T extractMax (); /// TODO
  void increaseKey (T & task, unsigned new_priority); /// TODO, new_priority >= old_priority
};

#endif /// PRIORITY_QUEUE_H
