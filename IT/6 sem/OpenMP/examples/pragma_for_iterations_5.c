#include <stdio.h>
#include <omp.h>

int main() {
  int count = 0;
#pragma omp parallel
{
#pragma omp atomic
  count++;
}
  printf("Num of threads: %d\n", count);
  return 0;
}
