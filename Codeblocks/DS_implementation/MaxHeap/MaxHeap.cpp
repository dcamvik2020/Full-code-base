#include <iostream>
#include <iomanip>

#include "MaxHeap.h"

MaxHeap::MaxHeap(const int * x, unsigned n) : arr_size(n + 1),  arr(new int[n + 1]()) {
  if (x != NULL && n == 0) {
    std::cout << "Wrong initialisation\n";
    return;
  }
  arr[0] = n; /// heap_size = arr_size - 1 = n;
  for (unsigned i = 1; i <= n; ++i) {
    arr[i] = x[i - 1];
  }

  /// immediately make a heap from the array
  BuildMaxHeap();
}

void MaxHeap::BuildMaxHeap() {
  /// Left(i), Right(i) --> obvious : n/2 + 1, ..., n --> leaves
  for (unsigned i = (arr[0]) / 2; i; --i) { /// because indexes from 1
    MaxHeapify(i);
  }
}

int MaxHeap::HeapExtraxtMax() {
  if (arr[0] == 0) {
    //std::cout << "ExtractMax : heat is empty\n";
    return INT32_MAX;
  }
  int max = arr[1];
  arr[1] = arr[arr[0]];
  --arr[0];
  MaxHeapify();
  return max;
}

void MaxHeap::MaxHeapInsert(int x) {
  ++arr_size;
  int * b = new int[arr_size];
  for (unsigned i = 0; i < arr_size - 1; ++i) {
    b[i] = arr[i];
  }
  ++b[0];
  unsigned i;
  for (i = arr_size - 1; i > 0 && arr[Parent(i)] < x; i = Parent(i)) {
    b[i] = b[Parent(i)];
  }
  b[i] = x;
  delete [] arr;
  arr = b;
}

void MaxHeap::MaxHeapify(unsigned i) {
  if (i > (unsigned) arr[0]) /// i > heap_size
    return;

  unsigned l = Left(i), r = Right(i);
  unsigned largest_id = i;
  /// remember : maybe left, right don't exist (left > arr[0])
  /// arr[0] = heap_size ---> node indexes in [1; heap_size]
  /// also remember ---> left <= arr[0] <=> left <= heap_size
  if (l <= (unsigned) arr[0] && arr[l] > arr[largest_id])
    largest_id = l;
  if (r <= (unsigned) arr[0] && arr[r] > arr[largest_id])
    largest_id = r;

  /// if one of children is bigger then i(parent) ---> heapify
  if (i != largest_id) {
    int buf = arr[i];
    arr[i] = arr[largest_id];
    arr[largest_id] = buf;

    MaxHeapify(largest_id);
  }
}

void MaxHeap::MaxHeapSort() {
  if (arr_size == 1) {
    std::cout << "HeapSort : heap is empty\n";
    return;
  }
  BuildMaxHeap();
  /// arr[0] = heap_size;
  int buf;
  for (unsigned it = arr[0]; it >= 1; --it) {
    buf = arr[1];                 /// swap the greatest element with
    arr[1] = arr[it];             /// the last in array and decrease
    arr[it] = buf;                /// heap_size = arr[0] - 1
    --arr[0];                     /// --heap_size;
    MaxHeapify(1);                /// get the largest as a root
  }
  arr[0] = arr_size - 1;
}

void MaxHeap::print() {
  if (arr[0] == 0) {
    std::cout << "Heap is empty\n";
    return;
  }

  for (unsigned i = 1; i < arr_size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

