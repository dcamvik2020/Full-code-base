/// This file.h is given to us
#include "sum_reverse_sort.h"
#include <algorithm>

int Sum (int x, int y) {
  return x + y;
}

string Reverse (string s) {
  char c;
  unsigned size = s.size();
  for (unsigned i = 0; i < size / 2; ++i) {
    c = s[i];
    s[i] = s[size - i - 1];
    s[size - i - 1] = c;
  }
  return s;
}

void Sort (vector<int> & nums) {
  sort(nums.begin(), nums.end());
}
