#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL));
    unsigned a;
    scanf("%u", &a);
    printf("%u\n", 1 + rand() % a);
    return 0;
}
