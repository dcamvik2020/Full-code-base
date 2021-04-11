#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
  const size_t MAX_OBJECT_COUNT = 100'000;
  int n;
  cin >> n;


  /// task : insert every object before the object with
  ///        given number (obj before next_obj)
  /// 
  ///        if next_obj isn't in the line ---> push_back(obj)

  using position = list<int>::iterator;
  list<int> line;
  vector<position> pos(MAX_OBJECT_COUNT, line.end());

  int obj, next_obj;
  for (int i = 0; i < n; ++i) {
    cin >> obj >> next_obj;
    pos[obj] = line.insert(pos[next_obj], obj);
  }
  for (auto x : line) {
    cout << x << "\n";
  }
  cout << endl;
  return 0;
}
