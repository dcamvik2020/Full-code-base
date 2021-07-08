#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///take n, m from input
///create a 2-dimensioned array and fill it random numbers
///print the array in output

#define MAX_DIMENSION 10

int main() {
    FILE *input, *output;
    unsigned m, n;
    unsigned i, j;
    if ((input = fopen("input.txt", "r")) != NULL)
    {
        if ((output = fopen("output.txt", "w")) != NULL)
        {
            fscanf(input, "%u %u", &m, &n);
            printf("%u %u\n\n", m, n);
            if (m > MAX_DIMENSION) m = MAX_DIMENSION;
            if (n > MAX_DIMENSION) n = MAX_DIMENSION;
            srand(time(NULL));
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++) {
                    fprintf(output, "%8d ", rand());
                    //printf("%8d ", rand());
                }
                fprintf(output, "\n");
                //printf("\n");
            }
        }
        else
        {
            fclose(input);
        }
    }
    fclose(output);
    fclose(input);
}
