#include <vector>
#include <iostream>

int main () {
  std::vector<std::vector<int>> a(5, std::vector<int>(3, 7));
  for (unsigned i = 0; i < 15; ++i) {
    auto ptr_1 = a.data();
    std::cout << ptr_1[i / 4][i % 4] << " ";
  }
  std::cout << "\n";
  return 0;
}

/// output :
/// 7 7 7 0 7 7 7 0 7 7 7 0 7 7 7 ---> not all are 7 ....
