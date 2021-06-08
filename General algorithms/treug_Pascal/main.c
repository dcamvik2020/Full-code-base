#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, x = 1;
    int a[100] = {0}, b[100] = {0};
    int k = 0;
    scanf("%d", &N);
    b[1] = b[0] = a[0] = 1;
    //printf("b[1] = %d, b[0] = %d, a[0] = %d\n\n", b[1], b[0], a[0]);
    while (x <= N)
    {
        k = 0;
        while (a[k])
        {
            printf("%d ", a[k]);
            k++;
        }
        puts("");
        k = 0;
        while (b[k])
        {
            //printf("NO");
            printf("%d ", b[k]);
            k++;
        }
        puts("");
        a[k] = a[0] = 1;
        for (i = 1; i < k; i++)
        {
            a[i] = b[i] + b[i-1];
        }
        b[++k] = b[0] = 1;
        for (i = 1; i < k; i++)
        {
            b[i] = a[i] + a[i-1];
        }
        x++;
        //for (i = 0; i < N - x; i++) printf(" ");
        //for (i = 0; i < x; i++) printf("%d", a[i])
    }

    printf("Hello world!\n");
    return 0;
}
