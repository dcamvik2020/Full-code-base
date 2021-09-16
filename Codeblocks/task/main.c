#include <stdio.h>
#include <stdlib.h>

/// Artists, masterpieces. Artists don't need the rest. They work one after another (delta_time = 0).
/// For any masterpiece: any moment in time only 1 artist can work on it.
/// time[i][j] = time for j artist at i masterpiece.
/// We need to find for each masterpiece the moment when it will be ready.

void time_search(int (*a)[5], int *time, int m, int n)
{
    int i = 1;
    for (; i <= m; i++)                /// moment(finishing masterpiece ¹ i) = time(waiting (n-1) artists) + time(working of artist ¹ n)
    {                                  /// => recursive equation

    }
}

int main()
{
    int n, m, i, j, (*a)[5] = NULL, *time = NULL;
    scanf("%d %d", &m, &n);
    a = (int(*)[5]) calloc(m, 5*sizeof(int));
    time = (int*) calloc(m+1, sizeof(int));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &(a[i])[j]);
        }
    }
    time_search(a, time, m, n);
    for (i = 1; i <= m; i++)
    {
        printf("%d \n", time[i]);
    }
    puts("");
    free(time);
    free(a);
    return 0;
}
