/// Have : N diplomas with same sizes h, w
/// Know : can't turn diplomas, 2 diplomas don't have common points
/// Need : pin them all on square board with min size

/// 1 <= h, w, N <= 10^9
/// ---> use long long, not int/unsigned
/// that's because ( unsigned + unsigned ) can overloop
/// integer iverheap

#include <iostream>

int main ()
{
  long long w, h, N;
  std::cin >> w >> h >> N;

  long long l, r; /// min, max board sizes
  l = 0; r = N * std::min(w, h);
  while (l < r)
  {
    long long m = (l + r) / 2;
    //unsigned kx = m / w ;
    //unsigned ky = m / h ;
    if ((m / w) * (m / h) >= N)
      r = m;
    else
      l = m + 1;
  }
  std::cout << l << "\n";
  return 0;
}
