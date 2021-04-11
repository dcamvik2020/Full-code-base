#include <iostream>

void PrintSubStr(const char * start, const char * finish) {
  std::cout << "|";

  // WARNING : pointers of the same type equal if and only they are both nullptr
  for (const char * ptr = start; int(finish - ptr); ++ptr)
    std::cout << *ptr;
  std::cout << "|";
}

int Pow(int a, size_t n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return a * Pow(a, n-1);
  int sqrtResult = Pow(a, n / 2);
  return sqrtResult * sqrtResult;
}
