#include <iostream>
#include <exception>

// Simple calculator :
//   # operations : +, -, *, /, unary + and - 
//   # without parentheses (, )
//   # number type : int
//   # garanted : the result may be represented as an int number

int CalcArithmExpr(const char * expr);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Too few arguments.\n";
  } else if (argc > 2) {
    std::cout << "Too many arguments.\n";
  } else {
    try {
      std::cout << "The result of expression = " << CalcArithmExpr(argv[1]) << "\n";
    } catch (const std::exception & e) {
      std::cout << e.what() << "\n";
    }
  }
  return 0;
}




class Term {
private:	
  int value;
public:
  int Evaluate() const {return value;}
  
  Term(const char * start, const char * finish) : value(0) {
    int curMultiplier = 0, sign = 1;
    char op = 0;
    for (const char * ptr = start; ptr != finish; ++ptr){
      for ( ; *ptr == ' '; ++ptr);
      if (*ptr == '-' || *ptr == '+') {
        sign = (*ptr == '+') ? 1 : -1;
        ++ptr;
      }
      for ( ; *ptr == ' '; ++ptr);

      if (*ptr < '0' || '9' < *ptr) {
        std::cout << "ptr - start = " << ptr - start << "\n";
        throw std::invalid_argument("Syntax error : there must be a number after +/-.");
      }
      
      for ( ; '0' <= *ptr && *ptr <= '9'; ++ptr) {
        curMultiplier = curMultiplier * 10 + (*ptr - '0');
      }
      
      if (curMultiplier == 0) {
        if (op == '/') {
          throw std::invalid_argument("Semantic error : division by zero.");
	}
        value = 0;
	break;
      }

      if (op == 0) {
        value = sign * curMultiplier;
      } else if (op == '*') {
        value *= sign * curMultiplier;
      } else {
        value /= sign * curMultiplier;
      }
      curMultiplier = 0;
      sign = 1;
      for ( ; *ptr == ' '; ++ptr);
      if (*ptr == '\0' || finish - ptr == 0) {
        break;
      }
      if (*ptr != '*' && *ptr != '/') {
	std::cout << "Problem :\n"
		  << "\t*ptr = " << *ptr << "\n"
		  << "\tcurMultiplier = " << curMultiplier << "\n";
        throw std::invalid_argument("Syntax error : there must be an operation after a number.");
      }
      op = *ptr;
      ++ptr;
    } 
  }
};

// strategy :
//   # get terms one by one
//     * two pointers for start and finish
//     * current term from (start) to (finish - 1)
//   # parse each term and calculate it
//     * in each term parse multipliers with their signs
//     * remember the current term value
void PrintSubStr(const char * start, const char * finish) {
  std::cout << "|";
  
  // WARNING : pointers of the same type equal if and only they are both nullptr
  for (const char * ptr = start; int(finish - ptr); ++ptr)
    std::cout << *ptr;
  std::cout << "|";
}

int CalcArithmExpr(const char * expr) {
  int result = 0;
  char lastSymbol = 0;
  const char * curTokenStart = expr;
  std::cout << "\n";
  for (const char * curTokenFinish = expr; *curTokenFinish; ) {
    //if (*curTokenFinish == ' ') continue;

    // find the end of curToken
    for ( ; *curTokenFinish && *curTokenFinish != '-' && *curTokenFinish != '+'; ++curTokenFinish);
    if (*curTokenFinish) {
      if (curTokenStart == curTokenFinish) {
        ++curTokenFinish;
	continue;
      } else {
        for (const char * tmp = curTokenFinish - 1; tmp - expr >= 0; --tmp) {
          if (*tmp == ' ') continue;
          else {
            lastSymbol = *tmp;
            break;
          }
        }
        if (lastSymbol == '*' || lastSymbol == '/') {
          ++curTokenFinish;
	  continue;
	}
      }
    }

    // no need to use "try-catch" block because if constructor Term()
    // throws an exception then "catch" in main handles it
    std::cout << "The substring is : "; PrintSubStr(curTokenStart, curTokenFinish); std::cout << "\n"; 
    result += Term(curTokenStart, curTokenFinish).Evaluate(); 
    curTokenStart = curTokenFinish;
  }
  std::cout << "\n";
  return result;
}
