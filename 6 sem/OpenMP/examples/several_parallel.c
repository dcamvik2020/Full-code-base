#include <stdio.h>
#include <omp.h>

/// int omp_in_parallel(void);
/// returns 1 if was called from parallel section



int main(/*int argc, char *argv[]*/) {

  int counter = 0;
#pragma omp parallel reduction(+: counter)
{
  counter = 1;
  printf("thread %d\n", omp_get_thread_num());
#pragma omp single 
{
    printf("\tTotal threads = %d\n", omp_get_num_threads());
    printf("\tParallel region 1\n");

    /// get current # of available threads
    /// it can change dynamically
}

}
  printf("counter after section 1 = %d\n\n", counter);


  omp_set_num_threads(2);
  /// but if we set it via pragma --> its priority is higher
#pragma omp parallel num_threads(3)
{
  //if (rank == 0) {
    printf("Parallel region 2\n\n");
  //  printf("threads = %d\n\n", omp_get_thread_num());
  //}
}
#pragma omp parallel
{
  printf("non-master thread from parallel region 3\n");
#pragma omp master
  {
    printf("master thread from parallel region 3\n");
  }
}
  return 0;
}
