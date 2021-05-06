/// u'_{t} = c^2 * u''_{xx}, c = 1
/// u(x, 0) = f(x), f(x) = 0
/// u(0, t) = a, a = 0
/// u(len, t) = b, len = 1, b = 1

/// 0 <= x <= len, 0 <= t <= T
/// dx <-> step by (x), dt <-> step by (t)
/// T is a parameter from console

/// Explicit difference scheme:
/// u^{n+1}_{m} = u^{n}_{m} + (c^2 * dt / dx^2) * (u^{n}_{m+1} - 2*u^{n}_{m} + u^{n}_{m-1})
/// it is fixed : c^2 * dt / dx^2 = 0.3
/// n <-> time step, m <-> coordinate step is from 1 to N
/// N is a parameter from console
/// two rows are kept : u^{n} and U^{n+1}

/// Result : txt file with u(x, T) :
/// 0 u(0, T)
/// h u(h, T)
/// ...
/// len u(len, T)

/// Use MPI_Ssend, MPI_Recv, time complexity of sens is O(1)
/// Plots for S_p = T_1 / T_p, p = # of processes

/// rank = 0 : 0 dx 2dx                      but we need 3dx
/// rank = 1 :        3dx 4dx 5dx            but we need 2dx, 6dx 
/// rank = 2 :                 6dx 7dx 8dx   but we need ... 
/// so, we need in every process get extra values from neighbours

/// u^{n+1} <-> next_row
/// u^{n} <-> cur_row

/// It's convinient to draw a table of values 
/// row <-> moment of time
/// column <-> coordinate fixed, time evolution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mpi.h>

int main(int argc, char ** argv) {
	
  // # of parts of [0, l]
  const unsigned N = atoi(argv[1]); // maybe it should be not 700 ... but 10^6 at least
                                    // else : time(messages sends) >> computing time
  // integrating time
  const double T = atof(argv[2]); 
  const double a = 0.0, b = 1.0, len = 1.0; //, c = 1.0;
  const double dx = len / N;
  // dt * c^2 / dx^2 = 0.3, c = 1
  const double dt = 0.3 * dx * dx; 
  const unsigned time_parts = T / dt;  

  /// for getting the time of program's work
  double start_time, finish_time;
  unsigned size, rank;

  /// two nearest moments of time (rows of N+1 values for coordinates)
  double * cur_row = (double *) malloc((N + 1) * sizeof(double));
  double * next_row = (double *) malloc((N + 1) * sizeof(double));
  double * tmp_row;
 
  unsigned m, n; /// look higher
  
  /// boundaries of coordinates for each process
  unsigned l, r;
  // extra values for boundaries of each process's areas
  double l_extra, r_extra;

  start_time = MPI_Wtime();
 
  for (l = 0; l <= N; ++l) cur_row[l] = a;
  next_row[N] = b; /// u(len, t) = b = 1, len = 1
  
  MPI_Init(&argc, &argv);
  const int tag = 99;
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Comm_size(comm, (int*)&size);
  MPI_Comm_rank(comm, (int*)&rank);

 /* printf("2\n"); 
  printf("sdfsjdnlgjbsndlgjbsljbgljsb\n");
  printf("rank = %u\n", rank);
 */ if (rank == 0) {
    printf("dt = %.15lf\n", dt);
    printf("time_parts = %u\n", time_parts);
  }


  // main part <-> MPI
  for (n = 0; n <= time_parts; ++n) {
	  //printf("rank = %u\n", rank);
    /// we will work with m : l <= m < r
    l = (rank == 0) ? 1 : rank * (N / size);
    r = (rank == size - 1) ? N : (rank + 1) * ( N / size);
    
    /// default : l_extra = 0, r_extra = 1 (if size = 1)
    l_extra = 0, r_extra = 1;
    /// send our interior values to neigbours
    /// also get extra values from neighbours
    if (size > 1) {
      if (rank % 2 == 0) {
        if (rank == 0) {
          MPI_Ssend(&cur_row[r-1], 1, MPI_DOUBLE, rank+1, tag, comm);
	  MPI_Recv(&r_extra, 1, MPI_DOUBLE, rank+1, tag, comm, NULL);
	} else if (rank == size - 1) {
          MPI_Ssend(&cur_row[l], 1, MPI_DOUBLE, rank-1, tag, comm);
	  MPI_Recv(&l_extra, 1, MPI_DOUBLE, rank-1, tag, comm, NULL);
	} else {
          MPI_Ssend(&cur_row[l], 1, MPI_DOUBLE, rank-1, tag, comm);
	  MPI_Recv(&l_extra, 1, MPI_DOUBLE, rank-1, tag, comm, NULL);

	  MPI_Ssend(&cur_row[r-1], 1, MPI_DOUBLE, rank+1, tag, comm);
	  MPI_Recv(&r_extra, 1, MPI_DOUBLE, rank+1, tag, comm, NULL);
	}
      } else if (rank % 2 == 1) {
        if (rank == size - 1) {
          MPI_Recv(&l_extra, 1, MPI_DOUBLE, rank-1, tag, comm, NULL);
	  MPI_Ssend(&cur_row[l], 1, MPI_DOUBLE, rank-1, tag, comm);
	} else {
          MPI_Recv(&l_extra, 1, MPI_DOUBLE, rank-1, tag, comm, NULL);
	  MPI_Ssend(&cur_row[l], 1, MPI_DOUBLE, rank-1, tag, comm);

	  MPI_Recv(&r_extra, 1, MPI_DOUBLE, rank+1, tag, comm, NULL);
	  MPI_Ssend(&cur_row[r-1], 1, MPI_DOUBLE, rank+1, tag, comm);
	}
      }
    }
    
    /// generate interior part of next_row for current process
    for (m = l + 1; m < r - 1; ++m) {
      next_row[m] = cur_row[m] + 0.3 * (cur_row[m+1] - 2 * cur_row[m] + cur_row[m-1]);
    }
    
    /// generate left and right elements
    next_row[l] = cur_row[l] + 0.3 * (cur_row[l+1] - 2 * cur_row[l] + l_extra);
    next_row[r-1] = cur_row[r-1] + 0.3 * (r_extra - 2 * cur_row[r-1] + cur_row[r-2]);
    
    /// save next_row in cur_row, next turn
    tmp_row = next_row;
    next_row = cur_row;
    cur_row = tmp_row;

    next_row[0] = 0;
    next_row[N] = b;
  }

  /// last part
  if (rank == 0) 
  {
    double x = 0;
    unsigned i;
    FILE * results;
    if ((results = fopen("results.txt", "w")) == NULL) {
      perror("fopen");
      return 0;
    }
    for (i = 1; i < size; ++i) {
      /// we will work with m : l <= m < r
      l = i * (N / size);
      r = (i == size - 1) ? N : (i + 1) * ( N / size);
      MPI_Recv(&cur_row[l], r - l, MPI_DOUBLE, i, 99, comm, NULL);
    }
 
    // print data to a file
    for (l = 0; l <= N; ++l, x += dx) {
      fprintf(results, "%lf  -->  u(%lf, T)  =  %lf\n", x, x, cur_row[l]);
    }
    fclose(results);

    // finish, get time of work
    finish_time = MPI_Wtime();
    printf("Proccesses : %d\nThat took %f seconds.\n", size, finish_time - start_time);
  } 
  else 
  {
    /// we will work with m : l <= m < r
    l = rank * (N / size);
    r = (rank == size - 1) ? N : (rank + 1) * ( N / size);
    MPI_Ssend(&cur_row[l], r - l, MPI_DOUBLE, 0, 99, comm);
  }

  MPI_Finalize();
  free(cur_row);
  free(next_row);
  //free(tmp_row);
  return 0;
}
