#include <iostream>

#include "functions.h"
#include "Func.h"

double derivative(double x) {
  double res; //, df;
//  double eps = 1e-6; // accuracy
  double dx = 1e-10;
  res = f(x+dx) - f(x);
  res /= dx;
  return res;
}

int main() {
  double x;
  std::string func;
  Func f(func);

  std::cout << "Enter the func name : ";
  std::cin >> func;
  std::cout << "Enter the value x for func(x) : ";
  std::cin >> x;
  
  std::cout << "Derivative of func at point x : ";
  std::cout << "d/dx " << func << "(" << x << ") = ";
  std::cout << derivative(f, x) << "\n";
  return 0;
}
