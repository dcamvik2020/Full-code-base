#include <iostream>
#include <stack>
#include <iomanip>

bool isValid(std::string s) {
  std::stack<char> par;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      par.push(c);
    } else {
      if (par.empty() == true) return false;
      if (par.top() == '(' && c != ')') return false;
      if (par.top() == '{' && c != '}') return false;
      if (par.top() == '[' && c != ']') return false;
               
      par.pop();
           
    }
  }
  return (par.empty() == true);
}

int main() {
  std::string exp;
  std::cout << "parentheses expression (,[,{ : " << std::endl;
  std::cin >> exp;
  std::cout << (isValid(exp) == true ? "good expression" : "bad expression") << std::endl;
  return 0;
}
