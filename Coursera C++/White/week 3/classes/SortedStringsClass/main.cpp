#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        SS.push_back(s);
        sort(begin(SS), end(SS));
    }
    vector<string> GetSortedStrings() {
        return SS;
    }
private:
    vector<string> SS;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
