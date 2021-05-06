#include <stdio.h>
#include <mpi.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>

double f(double x) {
  return sqrtf(4 - x*x);
}

int main(int argc, char * argv[]) {
  double start_time, finish_time;

  //int size, rank;
  unsigned size, rank;
  unsigned i;
  double a = 0.0, b = 2.0;
  double x1, x2, dx, integral = 0.0;
  double tmp = 0;

  const unsigned N = atoi(argv[1]);
  dx = (b - a) / N;
  start_time = MPI_Wtime();

  MPI_Init(&argc, &argv);
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Comm_size(comm, (int*)&size);
  MPI_Comm_rank(comm, (int*)&rank);

  // one process accumulates all the information
  if (rank == size - 1) {
    for (i = N / size * (size - 1); i < N - 1; ++i) {
      x1 = a + i * (b - a) / N;
      x2 = x1 + dx;
      integral += (f(x1) + f(x2)) * dx / 2;
    }
    for (i = 0; i < size - 1; ++i) {
      MPI_Recv(&tmp, 1, MPI_DOUBLE, i, 99, comm, NULL);
      integral += tmp;
    }
    printf("integral from a = %lf to b = %lf, f(x), result = %.6lf\n", a, b, integral);

    finish_time = MPI_Wtime();
    printf("Proccesses : %d\nThat took %f seconds.\n", size, finish_time - start_time);
  } else {
    // other processes send information to last process
    //printf("ID = %02d -- integral : %03.6lf -->", rank, integral);
    for (i = N / size * rank; i < N / size * (rank + 1) - 1; ++i) {
      x1 = a + i * (b - a) / N;
      x2 = x1 + dx;
      integral += (f(x1) + f(x2)) * dx / 2;

    }
    //printf(" %lf\n", integral);
    MPI_Send(&integral, 1, MPI_DOUBLE, size - 1, 99, comm);
  }
  MPI_Finalize();

  return 0;
}
