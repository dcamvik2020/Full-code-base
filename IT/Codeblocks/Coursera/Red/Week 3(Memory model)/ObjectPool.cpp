#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
private:
  set<T*> allocated;
  queue<T*> deallocated;
public:
  ObjectPool() {}

  T* Allocate() {
    T* new_obj;
    if (deallocated.size() > 0) {
      new_obj = deallocated.front();
      deallocated.pop();
    } else {
      new_obj = new T();
    }
    allocated.insert(new_obj);
    return new_obj;
  }

  T* TryAllocate() {
    if (deallocated.size() == 0) {
      return nullptr;
    }
    T* new_obj = deallocated.front();
    deallocated.pop();
    allocated.insert(new_obj);
    return new_obj;
  }

  void Deallocate(T* object) {
    if (allocated.find(object) == end(allocated)) {
      throw invalid_argument("");
    }
    deallocated.push(object);
    allocated.erase(object);
  }

  ~ObjectPool() {
    T* tmp;
    size_t dealloc_size = deallocated.size();
    for (T* pointer : allocated) {
      delete pointer;
    }
    allocated.clear(); /// not needed, we can miss it
    for (size_t i = 0; i < dealloc_size; ++i) {
      tmp = deallocated.front();
      deallocated.pop();
      delete tmp;
    }
  }
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
