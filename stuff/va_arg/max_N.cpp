#include <iostream>
#include <stdarg.h>

#include <vector>
#include <climits>
int max_N(int N, ...)
{
  if (N == 0) return INT_MIN;
  int max, i;
  va_list list;
  va_start(list, N);
    max = va_arg(list, int);
    for (i = 0; i < N - 1; ++i)
      max = std::max(max, va_arg(list, int));
  va_end(list);
  return max;
}

int main ()
{
  int N;
  std::cin >> N;
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i)
    std::cin >> v[i];
  std::cout << max_N(N, std::initializer_list<int>(v.begin(), v.end()));
  return 0;
}
