#include <iostream>
#include "sum_reverse_sort.h"

using namespace std;

int main() {
  vector<int> v = {3, 9, 1, 5, 2, 6, 7, 98, 4, 2, 3, 3};
  Sort(v);
  for (unsigned i = 0; i < v.size(); ++i) cout << v[i] << " ";
  cout << endl;

  cout << Sum(v[0], v[1]) << endl;

  string s = "abcd";
  s = Reverse(s);
  cout << "s now = " << s << endl;
  return 0;
}
