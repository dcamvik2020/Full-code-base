#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Too few arguments!\n");
        return 1;
    }

    unsigned N = atoll(argv[1]);
    
    double T = atof(argv[2]);
    double a = 0.0, b = 1.0, c = 1.0, inv = 0.3, h = (b-a) / N;
    double tau = h * h  / c / c * inv;
    //int chunk_size = 3000;
    
    double * old_row = (double *)calloc(N, sizeof(double));
    double * new_row = (double *)calloc(N, sizeof(double));
    
    old_row[0] = new_row[0] = a;
    old_row[N-1] = new_row[N-1] = b;
 
    unsigned i, j;
    double start = omp_get_wtime();
#pragma omp parallel private(i)
    {
        for (i = 0; i * tau < T; i++)
        {
#pragma omp for schedule (static)  /// optimization --> compiler
            for (j = 1; j < N - 1; j++)
            {
                new_row[j] = old_row[j] + inv * (old_row[j-1] - 2 * old_row[j] + old_row[j+1]);
            }

    //#pragma omp barrier 
	    /// swap 2 rows
    #pragma omp master
            {
                double * tmp = new_row;
                new_row = old_row;
                old_row = tmp;
            }
    #pragma omp barrier
        }
    }

    printf("T = %lf\n", T);
    for (i = 0; i < N; i++)
    {
        printf("i = %9u, %10lf\n", i, old_row[i]);
    }

    double end = omp_get_wtime();
    printf("%lf\n", end - start);
    free(old_row);
    free(new_row);

    return 0;
}


// roundUP -- юнит-тесты на bash
// libInotify
