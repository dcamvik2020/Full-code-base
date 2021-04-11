#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 2; N > 1; i++)
    {
        if (N % i == 0)
        {
            printf("%d ", i);
            while(N % i == 0)
            {
                N /= i;
            }
        }
    }
    return 0;
}
