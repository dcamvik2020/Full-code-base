#include <stdio.h>
#include <stdlib.h>

unsigned DivMod(unsigned a, unsigned b, unsigned *r)
{
  if (b == 0)
  {
    fprintf(stderr, "Division by zero! Choose another values!\n");
    exit(-1);
  }
  if (r) // if (r != NULL)
    *r = a % b;
  else
  {
    fprintf(stderr, "NULL pointer exception!\n");
//    exit(-2);
  }
  return a / b;
}

int main(void)
{
  unsigned a, b, t, r;
  scanf("%u %u", &a, &b);
  t = DivMod(a, b, &r);
  printf("%u / %u = %u (mod = %u)\n", a, b, t, r);
  return 0;
}
