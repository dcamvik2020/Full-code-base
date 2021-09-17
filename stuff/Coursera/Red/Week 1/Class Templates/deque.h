#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template <typename T>
class Deque {
private:
  vector<T> forward;   /// ---> push_pop_back       |  [0;+inf)
  vector<T> reversed;  /// <--- push_pop_front      |  (-inf;0)
public:
  Deque() {}
  
  
  bool Empty() const {
    return forward.empty() && reversed.empty();
  }
  size_t Size() const {
    return forward.size() + reversed.size();
  }
  
  
  T& operator[](size_t index) {
    return this->At(index);
  }
  const T& operator[](size_t index) const {
    return this->At(index);
  }

  T& At(size_t index) {
    if (index >= this->Size()) {
      throw out_of_range("");
    }
    /// 0 <--> last element of reversed 
    if (reversed.size() == 0) {
      return forward[index];
    } else if (index < reversed.size()) {
      return reversed[reversed.size() - 1 - index];
    }
    return forward[index - reversed.size()]; 
  }
  const T& At(size_t index) const {
    if (index >= this->Size()) {
      throw out_of_range("");
    }
    /// 0 <--> last element of reversed 
    if (reversed.size() == 0) {
      return forward[index];
    } else if (index < reversed.size()) {
      return reversed[reversed.size() - 1 - index];
    }
    return forward[index - reversed.size()]; 
  }
  

  T& Front () {
    return this->At(0);
  }
  const T& Front () const {
    return this->At(0);
  }
  T& Back () {
    size_t size = this->Size();
    return this->At(size - 1);
  }
  const T& Back () const {
    size_t size = this->Size();
    return this->At(size - 1);
  }


  void PushFront(T x) {
    reversed.push_back(x);
  }
  void PushBack(T x) {
    forward.push_back(x);
  }
};

/*
int main() {
  Deque<int> deque;
  return 0;
}*/
