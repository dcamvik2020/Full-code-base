#ifndef MAX_HEAP_H
#define MAX_HEAP_H

/// non-ascending heap (parent >= children)
class MaxHeap {
private:
  unsigned arr_size;   /// real size of allocked memory = heap_size + 1
  int * arr;           /// arr[0] = heap_size, arr[1] --> root

public:
  MaxHeap(const int * x = nullptr, unsigned n = 0);
  
  unsigned Parent(unsigned i) {
    return i >> 2;
  }
  unsigned Left  (unsigned i) {
    return i << 2;
  }
  unsigned Right (unsigned i) {
    return (i << 2) + 1;
  }
  
  int HeapExtraxtMax();
  void BuildMaxHeap();
  void MaxHeapInsert(int x);
  void MaxHeapify(unsigned i = 1);

  void MaxHeapIncreaseKey(...); /// TODO

  void MaxHeapSort();
  void print();
  
  ~MaxHeap() {
    delete [] arr;
  }
};

#endif /// MAX_HEAP_H
