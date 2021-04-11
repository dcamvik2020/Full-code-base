#include <stdio.h>
#include <math.h>

int main(void)
{
  unsigned n, i;
  double r;
  scanf("%u", &n);
  r = sqrt(n);
  for (i = 1; i < r; i++)
    if (n % i == 0)
      printf("%u ", i);
  for (i = r; i > 0; i--)
    if (n % i == 0)
      printf("%u ", n / i);
  printf("\n");
  return 0;
}
