#include <omp.h>
#include <stdio.h>

int main() {
  int n;
#pragma omp parallel private(n)
{
  n = omp_get_thread_num();
#pragma omp sections
{
#pragma omp section
  printf("First section, task %d\n", n);
#pragma omp section
  printf("Second section, task %d\n", n);
}
  printf("Parallel section, task %d\n", n);
}
  return 0;
}
