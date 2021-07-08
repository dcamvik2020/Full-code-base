#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  if (argc != 2) return 0;
  unsigned N = atol (argv[1]);
  unsigned factorial = 1;

#pragma omp parallel num_threads(N) reduction(* : factorial)
{
  factorial = omp_get_thread_num() + 1;
#pragma omp master
  printf("number of threads N = %u\n", N);
}
  printf("factorial(%u) = %u\n", N, factorial);
  return 0;  
}
