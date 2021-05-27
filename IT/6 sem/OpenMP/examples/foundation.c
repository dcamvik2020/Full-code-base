#include <stdio.h>
#include <omp.h>

int main () {
#ifdef _OPENMP
  unsigned year = _OPENMP / 100, month = _OPENMP % 100;
  printf("OpenMP is supported, version: year %d, month %d.\n", year, month);
#endif

  return 0;
}
