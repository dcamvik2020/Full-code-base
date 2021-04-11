#include <iostream>
#include <vector>
#include <deque>

//using namespace std;

int size;
int left = 0, right = 0; /// parentheses
std::string s;
std::deque<char> deq = {};

void GetPar(std::vector<std::string> & res) {
  /// par = 2 * n    initially
  if (left + right == size) {
    for (int i = 0; i < size; ++i) s[i] = deq[i];
      res.push_back(s);
  } else if (left == size / 2) {
    deq.push_back(')');
    ++right;
    GetPar(res);
    deq.pop_back();
    --right;
  } else {       
    deq.push_back('(');
    ++left;
    GetPar(res);
    deq.pop_back();
    --left;
           
    if (left > right) {
      deq.push_back(')');
      ++right;
      GetPar(res);
      deq.pop_back();
      --right;
    }
  }
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> res;
  size = 2*n;
  s.resize(size);
  deq.push_back('(');
  ++left;
  GetPar(res);
  deq.pop_back();
  --left;
  return res;
}

int main() {
  int n;
  std::cout << "number of parenthesis (n) : ";
  std::cin >> n;
  std::cout << "all pairs of parenthesis (size = 2 * n) : " << std::endl;
  std::vector<std::string> res = generateParenthesis(n);
  for (auto & x : res) std::cout << x << std::endl;
  return 0;
}
