/// What we have : word W (lenW=g), line S
/// What we know : order of letters in W is changeable
///                   we can write "abcd" and "dcba" 
/// What we need : count ALL POSSIBLE APPEARANCES of W in S
/// Idea : sort by count

#include <iostream>
#include <map>


/// cntSymInS is empty firstly
void getMapByString(const std::string & s, std::map<char, int> & cntSymInS)
{
  for (const char & c : s)
    cntSymInS[c]++;
}


int main () {
  
  int g, lenS;
  std::cin >> g >> lenS;

  std::string W, S;
  std::cin >> W >> S;
  
  std::map<char, int> cntSymInW;
  getMapByString (W, cntSymInW);

  std::map<char, int> cntSymInPartS;
  getMapByString (S.substr(0, g), cntSymInPartS);

  int cntWAppearance = (cntSymInW == cntSymInPartS);
  for (int i = 1; i + g <= lenS; ++i)
  {
    cntSymInPartS [ S[i-1+g] ] ++;
    cntSymInPartS [ S[i-1] ] --;
    
    if (cntSymInPartS [ S[i-1] ] == 0)
      cntSymInPartS.erase( S[i-1] ) ;
    
    if (cntSymInW == cntSymInPartS)
      cntWAppearance++;
  }

  std::cout << cntWAppearance << "\n";
  return 0;
}
