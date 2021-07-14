/// Have : array of size N
/// Need : find 2 elements with max abs(subtraction)

#include <iostream>
#include <vector>

int main ()
{
  int N;
  std::cin >> N;
  if (N == 0)
    return 0;

  std::vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    std::cin >> arr[i];

  int min = arr[0], max = arr[0];
  for (int i = 0; i < N; ++i) {
    if (arr[i] > max) max = arr[i];
    else if (arr[i] < min) min = arr[i];
  }
  std::cout << "max elements' diff = " << max - min << "\n";
  return 0;
}
