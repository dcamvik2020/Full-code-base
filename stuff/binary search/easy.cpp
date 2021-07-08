/// Have : N pages; 2 printers --> 1 page per x, y seconds respectively; 
/// Know : can use both simultaneously, initially have 1 page
/// Need : min time for printing N pages

#include <iostream>

/// Note : n + m = N
bool checkGood(long long m, long long n, long long x, long long y)
{
  /// func <---> time : wait for last printer <---> max(time1, time2)
  /// time1 = m * x, time2 = n * y;
  unsigned prev_func_value = std::max(m * x , n * y);
  unsigned next_func_value = std::max((m + 1) * x , (n - 1) * y);

  return prev_func_value <= next_func_value;
}


unsigned getMinTime(long long N, long long x, long long y)
{
  /// find optimal # of pages for 1 printer = p1
  /// for 2 printer : N-1-p1
  long long p1_min = 0, p1_max = N;
  while (p1_min < p1_max)
  {
    long long m = (p1_min + p1_max) / 2;
	if (checkGood(m, N-m, x, y) == true)
	  p1_max = m;
	else
	  p1_min = m + 1;
  }

  long long time = std::max(p1_min * x , (N - p1_min) * y);
  return time;
}


int main ()
{
  long long N, x, y;
  std::cin >> N >> x >> y;

  long mintime = std::min(x, y) + getMinTime(N-1, x, y);
  std::cout << mintime << "\n";
  return 0;
}
