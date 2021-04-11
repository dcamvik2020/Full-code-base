#include "calculator.h"

// strategy :
//   # get terms one by one
//     * two pointers for start and finish
//     * current term from (start) to (finish - 1)
//   # parse each term and calculate it
//     * in each term parse multipliers with their signs
//     * remember the current term value

int CalcArithmExpr(const char * expr) {
  int result = 0;
  char lastSymbol = 0; 
  for (const char *curTokenStart = expr, *curTokenFinish = expr; *curTokenFinish; ) {
    // find the end of current token
    for ( ; *curTokenFinish && *curTokenFinish != '-' && *curTokenFinish != '+'; ++curTokenFinish);
    if (*curTokenFinish) {
      if (curTokenStart == curTokenFinish) {
        ++curTokenFinish;
	continue;
      } else {
        // if after * or / there is +/- , then there must be a number after +/- ("2 * -5")
        for (const char * tmp = curTokenFinish - 1; tmp - expr >= 0 && lastSymbol == ' '; lastSymbol = *tmp, --tmp);
        if (lastSymbol == '*' || lastSymbol == '/') {
          ++curTokenFinish;
	  continue;
	}
      }
    }

    // if constructor Term() throws an exception then main handles it
    result += Term(curTokenStart, curTokenFinish).Evaluate(); 
    curTokenStart = curTokenFinish; // token : [start, finish)
  }
  return result;
}


// updated version of CalcArithmExpr
int Compute(const char * expr) {
  return 0;
}
