#include <iostream>
#include <vector>

#include <climits>

/// YES <--> x in arr
/// NO  <--> x not in arr
/// for each of K numbers get answer YES/NO

unsigned binsearch (const std::vector<int> & arr, int x)
{
  unsigned l = 0, r = arr.size() - 1;
  while (l < r)
  {
    unsigned m = (l + r) / 2;
    if (arr[m] >= x)
	  r = m;
	else
	  l = m + 1;
  }
  return (arr[l] == x) ? l : UINT_MAX;
}


int main ()
{
  unsigned N, K;
  std::cin >> N >> K;

  std::vector<int> arr(N);
  for (unsigned i = 0; i < N; ++i)
    std::cin >> arr[i];

  for (unsigned i = 0; i < K; ++i)
  {
    int x;
	std::cin >> x;
	unsigned pos = binsearch(arr, x);
    if (pos == UINT_MAX) std::cout << "NO\n";
	else std::cout << "YES\n";
  }

  return 0;
}
