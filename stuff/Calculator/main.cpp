#include <iostream>
#include <exception>
#include "calculator.h"


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
