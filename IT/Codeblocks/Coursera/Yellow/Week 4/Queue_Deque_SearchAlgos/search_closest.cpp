#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border);
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

set<int>::const_iterator 
FindNearestElement(const set<int>& numbers, int border) {
  
  /// 1 check : not in set, < min or > max
  if (numbers.begin() == numbers.end() || border <= *(numbers.begin())) {
    return numbers.begin();
  } else if (*(prev(numbers.end())) <= border) {
    return prev(numbers.end());
  }
  
  /// 2 check : min < border < max
  auto right = numbers.lower_bound(border);
  if (*right == border) {
    return right;
  }
  auto left = prev(right);
  if (border - *left > *right - border) {
    return right;
  }
  return left;
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}

// 1 4 4 6 6
// 1
