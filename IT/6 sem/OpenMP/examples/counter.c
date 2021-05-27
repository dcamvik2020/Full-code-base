#include <stdio.h>
#include <omp.h>

int main(/*int argc, char *argv[]*/) {
  int count = 0;
  
  /// default number of threads = # of cores
  /// set # of threads : 
  /// 1) void omp_set_num_threads(int num);
  /// 2) main --> char * envp[] --> OMP_NUM_THREADS = 5 ./my_program
  ///
#pragma omp parallel reduction (+: count)
{
  count++;
  printf("Current value count: %d\n", count);
}
  printf("Number of threads: %d\n", count);
  return 0;
}
