#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int x = 5;
    ///x = 4; compilation error
    const int *p = x;
    ///*p = 6; compilation error
    ///p++; OK
    int * const q = x; /// indeed, x=const -> const int * const q = x;
    ///q++; compilation error
    ///*q = 4; runtime error
    printf("Hello world!\n");
    return 0;
}
