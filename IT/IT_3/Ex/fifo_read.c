#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 1000 + '\0'
#define N 1001

#define IF(func)       \
    if (!(func))       \
        perror(#func); \
    else               \

int main (int argc, char *argv[])
{
    int n, m, **array = NULL, i, j;
    FILE *file = NULL;
    char tmp;
    if (argc < 2)
    {
        puts("Too few arguments");
    } else {
        IF ((file = fopen(argv[1], "r")) != NULL)
        {
            // we have opened fifo --> read from it n, m
            if (fscanf(file, "%d %d", &n, &m) > 0)
            {
                fscanf(file, "%c", &tmp);
                
                // create the array for matrix and fill it
                array = (int **) malloc(n * sizeof(int *));
                for (i = 0; i < n; i++)
                {
                    array[i] = (int *) calloc(m, sizeof(int));
                    for (j = 0; j <= m - 2; j++)
                    {
                        fscanf(file, "%d", &array[i][j]);
                    }
                    fscanf(file, "%d %c", &array[i][j], &tmp);
                }
                
                // print transponed matrix
                for (j = 0; j < m; j++)
                {
                    for (i = 0; i < n; i++)
                    {
                        printf("%d ", array[i][j]);
                    }
                    puts("");
                }

                // free memory
                for (i = 0; i < n; i++)
                {
                    free(array[i]);
                }
                free(array);
            }
        }
        fclose(file);
        unlink(argv[1]);
    }
    return 0;
}
