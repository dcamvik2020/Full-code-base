#include <iostream>
#include <vector>

#include <algorithm>
#include <climits>
#include <ctime>

/// arr : less ---> bigger
unsigned binarySearch (const std::vector<int> & arr, int x)
{
  unsigned l = 0, r = arr.size() - 1;
  while (l < r)
  {
    unsigned m = (l + r) / 2;
	if (arr[m] >= x) 
	  r = m; /// because arr[m] may be = x
    else
	  l = m + 1; /// arr[m] < x ---> it's trash, not keep it
  }

  return (arr[l] == x) ? l : UINT_MAX;
}

int main ()
{
  srand(time(NULL));
  int x = rand() % 100;
  unsigned N = 15;
  std::vector<int> arr(N);
  for (unsigned i = 0; i < N; ++i) arr[i] = rand() % 100;

  std::sort(arr.begin(), arr.end());
  unsigned pos = binarySearch(arr, x);

  std::cout << "x = " << x << "\narray : ";
  for (unsigned i = 0; i < N; ++i) std::cout << arr[i] << " ";
  std::cout << "\n";
  if (pos == UINT_MAX)
    std::cout << "number " << x << " not found in array\n";
  else
    std::cout << "number " << x << " exists\n";

  return 0;
}
