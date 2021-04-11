#include <stdio.h>

int main(void)
{
  int n, i;
  scanf("%d", &n);
  for (i = 2; n > 1; i++)
    while (n % i == 0)
    {
      printf("%d ", i);
      n /= i;
    }
  printf("\n");
  return 0;
}
