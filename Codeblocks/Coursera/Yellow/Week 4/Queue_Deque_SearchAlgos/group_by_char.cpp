#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/// RandomIt ---> vector
/// all string consist of latin letters (little)
/// func gets sorted set of strings ---> find strings, beginning with "char prefix"
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end, char prefix) {
    /// find first string beginning with "char prefix"
    string tmp1(1, prefix);
    auto left  = lower_bound(range_begin, range_end, tmp1);
    
    /// find first string beginning with "char prefix + 1" --> need to find prev of it
    string tmp2(1, prefix + 1);
    auto right = lower_bound(range_begin, range_end, tmp2);
    
    /// empty segment : if there are no strings s : s[0] == prefix   <-->  (left == right)
    if (left == right) {
        return make_pair(left, left);
    }
    return make_pair(left, right);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  const auto m_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;
  return 0;
}

/// moscow murmansk
/// 2 2
/// 3 3
