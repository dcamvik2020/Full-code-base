#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int x;
    scanf("%d", &N);
    while(N % 10 == 0) N/= 10;
    while(N > 0)
    {
        x = N % 10;
        printf("%d", x);
        N /= 10;
    }
    return 0;
}
