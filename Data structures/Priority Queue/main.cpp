#include <iostream>
#include "priority_queue.h"

typedef struct Task {
  std::string  msg;
  unsigned priority; /// always >= 1, bigger--> more important
  Task (const std::string & msg_ = "", unsigned priority_ = 0)
  	: msg(msg_), priority(priority_) {}
} Task;

int main ()
{
  PriorityQueue<Task> queue;
  
  queue.insert(Task("task1", 1));
  queue.insert(Task("task2", 2));
  queue.insert(Task("task3", 3)); /// same priority
  queue.insert(Task("task4", 3)); /// same priority
  queue.insert(Task("task5", 5));
  queue.insert(Task("task6", 6));

  queue.sort();
  queue.print();

  return 0;
}
