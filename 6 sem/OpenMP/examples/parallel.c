#include <omp.h>
#include <stdio.h>

int main()
{
  
  printf("\n\n first part of example :\n");
  int n = 1;
  printf("serial (1): %d\n", n);
  /// private(n) --> uninitialized copies
  /// firstprivate(n) --> copies = n = 1 from master
#pragma omp parallel num_threads(5) firstprivate(n)
{
  printf("parallel (1): %d\n", n);
  n = omp_get_thread_num();
  printf("parallel (2): %d\n", n);
}
  printf("serial (2): %d\n", n);


  printf("\n\n second part of example :\n");
#pragma omp parallel num_threads(5)
{
  printf("Msg 1\n");
  /// barrier --> all threads come here and wait other
  /// --> after this barrier all threads start together
#pragma omp barrier
  printf("Msg 2\n");
}  
  
  return 0;
}
