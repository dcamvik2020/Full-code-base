/// Have : 2 strings --> a, b
/// Need : check that they are anagrammas (have the
///        the same set of letters in other order)

#include <iostream>
#include <map>

int main ()
{
  std::string a, b;
  std::cin >> a >> b;
  
  std::map<char, int> cntLettersA;
  std::map<char, int> cntLettersB;
  for (char c : a)
    cntLettersA[c]++;
  for (char c : b)
    cntLettersB[c]++;

  std::cout << (cntLettersA == cntLettersB) << "\n";
  return 0;
}
