#include <iostream>

class Token {
private:
  int token;
public:
  Token(const char* expr) : token(0) {
    int sign = 1;
    char op = 0;
    //std::cout << "\nexpr given in ctor = |" << expr << "|";
    for (size_t id = 0; expr[id]; ++id) {
      if (expr[id] == ' ' || expr[id] == '+') continue;
      
      if (expr[id] == '-') {
        sign = -sign;
	continue;
      }

      if (expr[id] == '*' || expr[id] == '/') {
        op = expr[id];
      } else {
        if (token == 0) token = expr[id] - '0';
	else if (op == '*') token *= expr[id] - '0';
	else if (op == '/') token /= expr[id] - '0';
      }
      //std::cout << "\n	token = " << token;
    }
    if (sign == -1) token = -token;
    //std::cout << "\ntoken after ctor = " << token << std::endl;
  }
  int Evaluate() const {return token;}
};


// + - * / and unary +/-
// only digits (numbers from 0 to 9)
// without () 
// expr = sum of tokens (numbers)
int Calc(char* expr, int first_token_sign = 1) {
  int next_token_sign;
  size_t id;
  if (*expr == '\0') return 0;
  
  // find the first digit in token
  for (id = 0; expr[id] < '0' || '9' < expr[id]; ++id);
 // std::cout << "\nid = " << id;

  // find the end of token
  for ( ; expr[id] && expr[id] != '-' && expr[id] != '+'; ++id);
 // std::cout << "\nid = " << id << "	expr[id] = " << expr[id] << "\n";
  if (expr[id] == '\0') return first_token_sign * Token(expr).Evaluate();
  
  next_token_sign = (expr[id] == '-') ? -1 : 1;
  expr[id] = '\0';
  
 // std::cout << "\n	first_token_sign = " << first_token_sign
 // 	    << "\n	next_token_sign = " << next_token_sign << "\n";
  return first_token_sign * Token(expr).Evaluate() + Calc(expr + id + 1, next_token_sign);
}


int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Too few arguments." << std::endl;
  } else if (argc > 2) {
    std::cout << "Too much arguments." << std::endl; 
  } else {
    std::cout << "result = " << Calc(argv[1]) << std::endl;
  }
  return 0;
}
