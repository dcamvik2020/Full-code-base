#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/// RandomIt ---> vector
/// all string consist of latin letters (little)
/// func gets sorted set of strings ---> find strings, beginning with "string prefix"
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end, const string & prefix) {
    /// find first string beginning with "char prefix"
    string tmp1(prefix);
    auto left  = lower_bound(range_begin, range_end, tmp1);
    
    /// find first string beginning with "char prefix + 1" --> need to find prev of it
    string tmp2(tmp1);
    tmp2[prefix.size() - 1]++;
    auto right = lower_bound(range_begin, range_end, tmp2);
    
    /// empty segment : if there are no strings s : s[0] == prefix   <-->  (left == right)
    
    return make_pair(left, right);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}

/// moscow motovilikha
/// 2 2
/// 3 3
