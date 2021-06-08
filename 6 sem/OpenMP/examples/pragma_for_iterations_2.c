#include <stdio.h>
#include <omp.h>

#include <unistd.h> /// for sleep()

int main(/*int argc, char *argv[]*/) {
  int i;
#pragma omp parallel private(i)
{
#pragma omp for schedule (static, 2)
  for (i = 0; i < 10; ++i) {
    printf("Thread %d iteration %d\n", omp_get_thread_num(), i);
    sleep(1);
  }
}
  return 0;
}
