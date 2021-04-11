#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/// Garanted : s != "", only latin letters and whitespaces, s[0] != ' ',
//             also s[last] != ' ', there are no 2 ' ' back-to-back
vector<string> SplitIntoWords(const string& s) {
  auto begin = s.begin();
  vector<string> words;
  do {
    auto it = find(begin, s.end(), ' ');
    words.push_back(string(begin, it));
    begin = it + 1;
  } while (begin <= s.end());
    
  return words;
}
 

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
