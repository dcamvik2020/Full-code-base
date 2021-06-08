#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;

template <typename First, typename Second>
pair<First, Second> operator * (const pair < First, Second > & a,
		                const pair < First, Second > & b); 

template <typename T>
vector<T> operator * (const vector < T > & a, const vector < T > & b);

template <typename Key, typename Value>
map<Key, Value> operator * (const map < Key, Value > & a, const map < Key, Value > & b);






template <typename First, typename Second>
pair<First, Second> operator * (const pair < First, Second > & a,
		                const pair < First, Second > & b) {
  return make_pair(a.first * b.first, a.second * b.second);
}

template <typename T>
vector<T> operator * (const vector < T > & a, const vector < T > & b) {
  unsigned size = a.size();
  vector<T> v(size);
  if (size == b.size()) {
    for (unsigned i = 0; i < size; ++i) {
      v[i] = a[i] * b[i];
    }
  }
  return v;
}

template <typename Key, typename Value>
map<Key, Value> operator * (const map < Key, Value > & a, const map < Key, Value > & b) {
  map<Key, Value> m;
  
  /// checks : sizes, keys
  if (a.size() != b.size()) {
    return m;
  }
  for (auto & it : a) {
    if (b.count(it.first) == 0) {
      m.clear();
      return m;
    }
    /// left part --> [],   right part --> .at because
    /// left part doesn't exist, but right exists
    m[it.first] = a.at(it.first) * b.at(it.first);
  }
  return m;
}

template <typename T>
T Sqr (T x) {
  return x * x;
}

int main() {
  // Пример вызова функции
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int >> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }
  return 0;
}
