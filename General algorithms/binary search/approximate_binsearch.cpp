#include <iostream>
#include <vector>

#include <climits>

/// for each of K numbers get the nearest number in arr
/// if there are > 1 such number ---> get minimal

unsigned approximate_binsearch (const std::vector<int> & arr, int x)
{
  unsigned l = 0, r = arr.size() - 1;
  unsigned norm = UINT_MAX;
  while (l < r)
  {
    unsigned m = (l + r) / 2;
    if (arr[m] >= x)
	  r = m;
	else
	  l = m + 1;
  }
  /// we got position of the first arr[i] >= x
  /// --> we check arr[i] and arr[i-1]
  if (l == 0 || arr.size() == 1) return l;
  if (arr[l] - x >= x - arr[l-1]) return l-1;
  return l;
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
	unsigned pos = approximate_binsearch(arr, x);
	std::cout << arr[pos] << "\n";
  }

  return 0;
}
