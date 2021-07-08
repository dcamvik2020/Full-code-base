/// What we have : dict with right stresses in words 
///                (pAge, plAnet, complEte, ...)
///                student's homework with stresses in words
/// Have error if: no stress, more than 1 stress or wrong stress
///           (last <-> lowercase word \in dict, word \notin dict)
/// What we need : count errors in homework;

#include <iostream>
#include <set>

int getLowerCase(std::string & word)
{
  int stresses = 0;
  for (char & c : word)
  {
    if (c < 'a' || 'z' < c)
    {
      c = c - 'A' + 'a';
      stresses++;
    }
  }
  return stresses;
}


int main () {
  int N;
  std::cin >> N;

  std::string word;
  std::set<std::string> dict;
  std::set<std::string> lowercasedict; /// without stresses
  for (int i = 0; i < N; ++i)
  {
    std::cin >> word;
    dict.insert(word);
    getLowerCase(word);
    lowercasedict.insert(word);
  }

  int cntErrors = 0;
  /// get word from homework;
  while (std::cin >> word)
  {
    if (dict.find(word) != dict.end())
    {
      continue;
    }
  
    int stresses = getLowerCase(word);
    if (stresses > 1 || stresses == 0 || lowercasedict.find(word) != lowercasedict.end())
      cntErrors++;
  }

  std::cout << cntErrors << "\n";
  return 0;
}
