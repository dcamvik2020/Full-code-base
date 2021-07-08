#include <stdio.h>
#include <omp.h>

//#define pragma_for

int main(/*int argc, char *argv[]*/) {
  int A[10], B[10], D[10], i, n;
  for (i = 0; i < 10; ++i) {
    A[i] = i;
    B[i] = 2*i;
    D[i] = 0;
  }

#ifdef pragma_for
  printf("with pragma for\n");
#pragma omp parallel num_threads(5) shared(A,B,D) private(i,n)
{
    n = omp_get_thread_num();
#pragma omp for
    for (i = 0; i < 10; ++i) {
      D[i] = A[i] + B[i];
      D[i]--;
      printf("Task %d element %d\n", n, i);
    }
}

#else

  printf("without pragma for\n");
#pragma omp parallel num_threads(5) shared(A,B,D) private(i,n)
{
    n = omp_get_thread_num();
    for (i = 0; i < 10; ++i) {
      D[i] = A[i] + B[i];
      D[i]--;
      printf("Task %d element %d\n", n, i);
    }
}

#endif

  return 0;
}
