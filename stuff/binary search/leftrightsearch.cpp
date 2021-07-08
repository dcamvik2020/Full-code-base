#include <iostream>
#include <vector>

#include <climits>

/// first appearance of x in sorted (ascending) arr
unsigned l_binsearch(const std::vector<int> & arr, int x)
{
  unsigned l = 0, r = arr.size() - 1;
  while (l < r)
  {
    unsigned m = (l + r) / 2;
    if (arr[m] < x)
	  l = m + 1;    /// arr[m] is not "good" --> l = m + 1
	else
	  r = m;
  }
  return l;
}

/// lsst appearance of x in sorted (ascending) arr
unsigned r_binsearch(const std::vector<int> & arr, int x)
{
  unsigned l = 0, r = arr.size() - 1;
  while (l < r)
  {
    unsigned m = (l + r + 1) / 2;
	if (arr[m] <= x)  /// we need to miss all arr[i] <= x
	  l = m;          /// and if arr[m] > x --> no need to
	else              /// keep arr[m] --> r = m-1, not r=m
      r = m - 1;      ///
  }
  return r;
}

int main() {
  unsigned N;
  std::cin >> N;

  std::vector<int> arr(N);
  for (unsigned i = 0; i < N; ++i)
    std::cin >> arr[i];

  int x;
  std::cin >> x;

  unsigned firstpos = l_binsearch(arr, x);
  unsigned lastpos = r_binsearch(arr, x);

  if (firstpos == UINT_MAX)
    std::cout << x << " is not in the array\n";
  else 
  {
    std::cout << x << " is found first at position " << firstpos + 1 << "\n";
    std::cout << x << " is found last  at position " << lastpos  + 1 << "\n";
  }
  return 0;
}
