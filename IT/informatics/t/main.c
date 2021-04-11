#include <stdio.h>

int main(void) {
    int a, b = 1;
    scanf("%d", &a);
    while (b <= a) b *= 3;
    b /= 3;
    printf("%d\n", b);
    while (b >= 1)
    {
        printf("%d", a/b);
        a -= (a/b) * b;
        b /= 3;
    }
    return 0;
}
