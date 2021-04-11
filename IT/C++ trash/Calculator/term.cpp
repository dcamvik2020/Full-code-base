#include "term.h"

Term::Term(const char * start, const char * finish) 
	: start(start), finish(finish), value(SimpleCompute(start, finish)) {}

/*
// strategy :
//   # split initial expression to small simple expressions
void Compute() {
  

}
*/


int Term::SimpleCompute(const char * start, const char * finish) {      
  int result = 0;
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
      result = 0;
      break;
    }

    if (op == 0) {
      result = sign * curMultiplier;
    } else if (op == '*') {
      result *= sign * curMultiplier;
    } else {
      result /= sign * curMultiplier;
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
  return result;
} 
