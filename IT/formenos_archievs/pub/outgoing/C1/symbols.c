#include <stdio.h>

#define MAX_ARR 26

int main(void)
{
  int A[MAX_ARR], i, m, n;
  char s[1001];
  for (i = 0; i < MAX_ARR; i++)
    A[i] = 0;
  scanf("%s", s);
  for (i = 0; s[i]; i++)
    A[s[i]-'a']++;
  m = 0;
  for (i = 0; i < MAX_ARR; i++)
    if (A[i])
      m++;
  scanf("%d", &n);
  if (n == m)
    puts("Yes");
  else
    puts("No");
  return 0;
}
