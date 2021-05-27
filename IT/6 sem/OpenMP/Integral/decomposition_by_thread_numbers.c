#include <stdio.h>
#include <stdlib.h>

#include <omp.h>

#include <string.h>
#include <math.h>

const double a = 0.0, b = 2.0;

int main(int argc, char * argv[]) {
  unsigned long long i, N = 0, num_threads = 1;
  char * end;
  if (argc > 2) {
    num_threads = strtoull(argv[1], &end, 10);
    N = strtoull(argv[2], &end, 10);
  } else {
    printf("Too few parameters.\n");
    return 0;
  }

  double integral = 0.0;
  double dx = (b - a) / N;
#pragma omp parallel num_threads(num_threads) reduction(+: integral) private(i)
  {   
    for (i = (unsigned long long) omp_get_thread_num(); i < N; i += num_threads) {
      printf("i = %lld,   thread_num = %d\n", i, omp_get_thread_num());
      double x = a + dx * i;
      double func = sqrt(4 - x * x);
      integral += func * dx;
    }
  }
  printf("Integral = %lf\n", integral);
  return 0;
}
