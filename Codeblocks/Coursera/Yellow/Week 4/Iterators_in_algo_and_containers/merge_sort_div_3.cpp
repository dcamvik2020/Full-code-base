#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if(range_end - range_begin < 2) {
    return;
  }
  
  /// GARANTED : size = 3 ^ k
  RandomIt middle_begin = range_begin + (range_end - range_begin) / 3;
  RandomIt right_begin = middle_begin + (range_end - range_begin) / 3;

  vector<typename RandomIt::value_type> left_part   (range_begin, middle_begin); 
  vector<typename RandomIt::value_type> middle_part (middle_begin, right_begin); 
  vector<typename RandomIt::value_type> right_part  (right_begin, range_end);
  MergeSort(left_part.begin(), left_part.end());
  MergeSort(middle_part.begin(), middle_part.end());
  MergeSort(right_part.begin(), right_part.end());

  vector<typename RandomIt::value_type> buffer;
  merge(left_part.begin(), left_part.end(), middle_part.begin(), middle_part.end(), back_inserter(buffer));
  merge(buffer.begin(), buffer.end(), right_part.begin(), right_part.end(), range_begin);

}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
