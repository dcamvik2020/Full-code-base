#include <iostream>
#include <vector>
#include <set>

using namespace std;

/// Task : order isn't important
template <typename T>
void RemoveDuplicates(vector<T>& elements) {
  set<T> s(elements.begin(), elements.end());                   /// PAY ATTENTION :
  elements.clear();                                             /// we may not keep set<T> in
                                                                /// memory... we may just
  unsigned size = 0;                                            ///
  for (auto it = s.begin(); it != s.end(); ++it) {              /// 1) sort vector (we have a referance)
    if ((size == 0) || (elements[size - 1] != *it)) {           /// 2) erase(... , unique(...), ... )
      elements.push_back(*it);                                  /// it is THEIR IDEA
      ++size;
    }
  }
}

int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}

