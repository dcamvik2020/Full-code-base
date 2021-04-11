#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  
  //cout << "border = " << border << endl;
  //cout << "my set : ";
  //for (auto & u : elements) cout << u << " ";
  //cout << endl << endl;
	
  auto it = elements.begin();
  for ( ; it != elements.end() && *it <= border; ++it);
  vector<T> v;
  if (it == elements.end()) {
    return v;
  }
 

  /// my way to return vector
  for (; it != elements.end(); ++it) {
    v.push_back(*it);
  }
  return v;

  /// their way to return vector
  /// return {it, elements.end()};
}

int main() {
  
  //srand(time(NULL));
  //int border = rand() % 100;;
  //vector<int> v(20);
  //for (int  & x : v) x = rand() % 100;  

  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 7)) {
  //vector<int> tmp = FindGreaterElements(set<int>(v.begin(), v.end()), border);
  //cout << "tmp.size = " << tmp.size() << endl << "tmp : ";
  //for (int x : tmp) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;

}


