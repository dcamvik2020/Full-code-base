#pragma once

#include <cstdlib>
#include <exception>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
private:
  size_t cur_size;
  size_t memory;
  T* arr;
public:
  SimpleVector() : cur_size(0), memory(0), arr(nullptr) {}
  explicit SimpleVector(size_t size) 
	: cur_size(size), memory(size), arr(new T[size]){}
  ~SimpleVector() {
    /*for (size_t i = 0; i < memory; ++i) {
      delete &arr[i];
    }*/
    delete[] arr;
  }

  T& operator[](size_t index) {
    return arr[index];
  }

  T* begin() {return arr;}
  T* end() {return arr + cur_size;}

  size_t Size() const {return cur_size;}
  size_t Capacity() const {return memory;}
  void PushBack(const T& value) {
    if (memory == 0) {
      memory = 1;
      arr = new T[1];
    } else if (cur_size > 0 && cur_size == memory) { 
      T* buf = new T[cur_size * 2];
      for (size_t i = 0; i < cur_size; ++i) {
        buf[i] = arr[i];
      }
      memory *= 2;
      delete[] arr;
      arr = buf;
    }
    arr[cur_size] = value;
    cur_size++;
  }

};
