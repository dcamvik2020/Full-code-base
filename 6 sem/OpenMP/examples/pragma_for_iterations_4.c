#include <stdio.h>
#include <omp.h>

int main() {
  int n = 0;
#pragma omp parallel
{
#pragma omp sections lastprivate(n)
{
#pragma omp section
  n=1;
#pragma omp section
  n=2;
}
  printf("Value n at thread %d: %d\n", omp_get_thread_num(), n);
}
  printf("Value of n: %d\n", n);
  return 0;
}
