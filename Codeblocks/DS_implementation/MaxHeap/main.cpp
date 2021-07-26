#include <iostream>
#include <iomanip>

#include "MaxHeap.h"

int main () {
  unsigned n, k;
  std::cin >> n >> k;
  
  int * a = new int[n];
  for (unsigned i = 0; i < n; ++i) {
    std::cin >> a[i];
//	a[i] = a[i] % 200;
  }

  MaxHeap heap(a, n);
  //heap.BuildHeap();
  //heap.HeapSort();
  //heap.print();
  
  heap.MaxHeapInsert(k);
  heap.print();

  delete [] a;
  return 0;
}
