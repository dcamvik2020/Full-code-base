#include <stdio.h>
#include <omp.h>

int main() {
  int n = 1;
  printf("initial n in master = %d\n", n);
  
#pragma omp parallel firstprivate(n)
  {
    /// if we use not firstpribate, but private(n) --->
    /// then the initial value is unknown (n is uninitialized)
    printf("\tn in thread is %d\n", n);
    n = omp_get_thread_num();
    printf("\tthread num = %d\n\n", n);
    
  }
  
  printf("n after parallel section is %d\n", n);

  return 0;
}
