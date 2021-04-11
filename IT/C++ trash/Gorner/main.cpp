#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

using vector_t = std::vector<size_t>;

// input : polinom
// output : factorised polinom

#include "check.h"
#include "factorisation.h"

#define MAX_EXPR_LEN 1024

int main(int argc, char * argv[]) {
  
/*	
  char * s = (char *) malloc(1024);
  std::cout << "s : |";
  //scanf("%s", s);
  fgets(s, 1024, stdin); 
  std::cout << "|" << s << "|" << std::endl;
  free(s);
  return 0;
*/		
	
  if (argc > 2) {
    std::cout << "Too many arguments.\n";
  } else {
    char * Polinom = (char *) malloc (MAX_EXPR_LEN);
    if (argc == 2) {
      Polinom = argv[1];
    } else {
      std::cout << "Enter the polinom : ";
      //scanf("%s", Polinom);
      if (!fgets(Polinom, MAX_EXPR_LEN, stdin)) {
        std::cout << "Runtime error : can't save the expression.\n";
	free(Polinom);
	return 0;
      }
      *(strrchr(Polinom, '\n')) = '\0';
    }

    char var;
    try {
      std::cout << "1 step : check syntax\n"; 
      var = Check(Polinom);
    } catch (std::exception & e) {
      std::cout << e.what() << "\n";
      free(Polinom);
      return 0;
    }

    vector_t degs, coeffs;
    std::cout << "2 step: get degrees and coefficients\n";
    GetDegsAndCoeffs(var, Polinom, degs, coeffs);
    for (size_t i = 0; i < degs.size(); ++i) {
      std::cout << degs[i] << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < degs.size(); ++i) {
      std::cout << coeffs[i] << " ";
    }
    std::cout << "\n";
    free(Polinom);
  }
  return 0;
}
