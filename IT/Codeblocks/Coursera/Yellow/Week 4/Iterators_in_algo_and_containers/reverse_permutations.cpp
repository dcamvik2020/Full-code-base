#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  unsigned N;
  cin >> N;
  vector<int> v(N);
  for (unsigned i = 0; i < N; ++i) {
    v[i] = N - i;
  }

  do {
    bool first = true;
    for (unsigned i = 0; i < N; ++i) {
      if (first == false) {
        cout << " ";
      }
      cout << v[i];
      first = false;
    }
    cout << endl;
  } while (prev_permutation(v.begin(), v.end()));
  return 0;
}
