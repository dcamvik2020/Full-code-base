#include <stdio.h>
#include <stdlib.h>

float x;
int main()
{
    scanf("%f", &x);
    __asm(
         "FLDPI\n"
         "FMUL _x\n"
         "MOVL $180, _x\n"
         "FIDIV _x\n"
         "FSIN\n"
         "FSTP _x\n"
         );
    printf("%g\n", x);
    return 0;
}
