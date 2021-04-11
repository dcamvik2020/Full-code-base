#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///return N numbers in random order

int main()
{
    int N, *a = NULL, i, x, k;
    srand((unsigned) time(NULL));
    scanf("%d", &N);
    a = (int*) calloc(N, sizeof(int));
    /*for (k = N; k; k--)
    {
        scanf("%d", &x);
        /*do
        {
            i = rand() % N;
        } while (a[i]);
        i = rand() % N;
        a[i] = x;
    }*/
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        k = rand() % N;
        x = a[k];
        a[k] = a[i];
        a[i] = x;
    }
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
    free(a);
    return 0;
}
