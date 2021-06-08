#pragma once

// #include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
private:
  T arr[N];  /// array<T, N> arr;
  size_t cur_size;
  size_t capacity;
public:
  explicit StackVector(size_t a_size = 0) 
          : cur_size(a_size), capacity(N) {
    if (N < a_size) {
      throw invalid_argument("");
    }	    
  }

  T& operator[](size_t index) {return arr[index];}
  const T& operator[](size_t index) const {return arr[index];}

  T* begin() {return arr;}
  T* end() {return arr + cur_size;}
  const T* begin() const {return arr;}
  const T* end() const {return arr + cur_size;}

  size_t Size() const {return cur_size;}
  size_t Capacity() const {return capacity;}

  void PushBack(const T& value) {
    if (cur_size == capacity) {
      throw overflow_error("");
    }
    arr[cur_size] = value;
    cur_size++;
  }
  T PopBack() {
    if (cur_size == 0) {
      throw underflow_error("");
    }
    T waste = arr[cur_size - 1];
    cur_size--;
    return waste;
  }
};

