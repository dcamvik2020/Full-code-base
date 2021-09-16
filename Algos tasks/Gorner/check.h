#include <exception>

// * only small latin letters may be variables
// * only one variable allowed in the polinom 
// * not 2 or more +/- one by one

char Check(const char * polinom) {	
  char variable = 0, lastSymbol = 0;
  for (const char * ptr = polinom; *ptr; ++ptr) {
    if (*ptr == ' ') continue;
    // check 1 : only 1 && latin variable
    if ('a' <= *ptr && *ptr <= 'z') {
      if (variable && *ptr != variable) {
        throw std::invalid_argument("Syntax error : more than one variable in the polinom.");
      }
      variable = *ptr;
    } else if (*ptr != '+' && *ptr != '-' && *ptr != '^' 
		           && (*ptr < '0' || '9' < *ptr)) {
      throw std::invalid_argument("Syntax error : not allowed symbols in the expression : " + std::to_string(*ptr) + ".");
    }

    // check 2 : +/- 
    if (*ptr == '+' || *ptr == '-') {
      if (lastSymbol == '+' || lastSymbol == '-') {
        throw std::invalid_argument("Syntax error : two operations one by one."); 
      }
    }
    lastSymbol = *ptr;
  }
  return variable;
}
