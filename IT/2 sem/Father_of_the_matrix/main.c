#include <stdio.h>

int main()
{
    int N, x0, x1, i;
    scanf("%d %d %d %d", &N, &x0, &x1, &i);
    printf("%d\n", (x0 + (x1 - x0 + N)*i) % N);
    return 0;
}
