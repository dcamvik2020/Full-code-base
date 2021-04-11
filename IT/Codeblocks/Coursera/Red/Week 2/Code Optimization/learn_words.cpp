#include <algorithm>
#include <string>
#include <vector>
#include <set>

#include <iostream>
#include <sstream>
using namespace std;




/// Task : optimize this class's methods 
class Learner {
 private:
  set<string> dict;         /// search in set is much
  // vector<string> dict;   /// fuster than in vector
                            /// also don't need to sort it
 public:
  int Learn(const vector<string>& words);
  
/*
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
      if (find(dict.begin(), dict.end(), word) == dict.end()) {
        ++newWords;
        dict.push_back(word);
      }
    }
    return newWords;
  }
*/

  vector<string> KnownWords() const;
/*
  vector<string> KnownWords() {
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());
    return dict;
  }
*/
};


/// optimized methods
int Learner::Learn(const vector<string>& words) {
  size_t old_size = dict.size();
  for (const auto& word : words) {
    dict.insert(word);
  }
  return dict.size() - old_size; // new learned words
}

vector<string> Learner::KnownWords() const {
  vector<string> tmp(dict.begin(), dict.end());
  return tmp;
}





/// for testing
int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
