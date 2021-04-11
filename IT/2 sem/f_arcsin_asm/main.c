#include <stdio.h>
#include <stdlib.h>

/// FSUB  --->   ST(0) = ST(0) - ST(1)
/// FDIV  --->   ST(0) = ST(0) / ST(1)

float Y;
int main()
{
    scanf("%f", &Y);
    __asm(
         "FLD _Y\n"     /// ST(0) = Y
         "FLD _Y\n"     /// ST(0) = Y             ST(1) = Y
         "FMUL _Y\n"    /// ST(0) = Y^2           ST(1) = Y
         "FLD1\n"       /// ST(0) = 1             ST(1) = Y^2      ST(2) = Y
         "FSUBP\n"      /// ST(0) = 1-Y^2         ST(1) = Y
         "FSQRT\n"      /// ST(0) = SQRT(1-Y^2)   ST(1) = Y
         "FPATAN\n"     /// ST(0) = ATAN(Y / SQRT(1-Y^2)) IN RADIANS


         "MOVL $180, _Y\n"
         "FIMUL _Y\n"   /// ST(0) = ATAN * 180
         "FLDPI\n"      /// ST(0) = PI            ST(1) = ATAN * 180
         "FDIVRP\n"     /// ST(0) = ATAN * 180 / PI
         "FSTP _Y\n"
         );
    printf("%g\n", Y);
    return 0;
}
