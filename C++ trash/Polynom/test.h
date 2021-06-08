#pragma once

#include <iostream>
#include <vector>
#include "Polynom.h"
#include "Monom.h"

void TestMonom() {
  Monom s1;
  Monom s2 ('x', 3, 2);
  Monom s3 (s2);
  Monom s4 (s2 + s3);
  Monom s5 (s1);

  std::cout << s5 << "\n";

  std::cout << "Test Monom : OK\n";
}


void TestPolynomSimple() {
  Polynom poly1;
  Polynom poly2('x');
  Monom my_monom('x', 3, 1);

  Polynom poly4(poly1);
  Polynom poly5 = poly2;

  std::cout << "Test Polynom Simple : OK\n";
}



void TestPolynomEvaluate() {
  std::vector<unsigned> degs = {2, 1, 0};
  std::vector<int> coeffs = {1, 2, 1};
  Polynom sqr('x', degs, coeffs);

  std::cout << "(3   + 1)^2 = " << 16    << " =?= " << evaluate(sqr, 3) << "\n";
  std::cout << "(4.5 + 1)^2 = " << 30.25 << " =?= " << evaluate(sqr, 4.5) << "\n";
  std::cout << "(2.5 + 1)^2 = " << 12.25 << " =?= " << evaluate(sqr, 2.5) << "\n";

  int x1 = 5;
  double x2 = 4.3;
  float x3 = 3.2;
  auto f1 = evaluate(sqr, x1);
  auto f2 = evaluate(sqr, x2);
  auto f3 = evaluate(sqr, x3);

  std::cout << "(5   + 1)^2 = " << 36    << " =?= " << f1 << "\n";
  std::cout << "(4.3 + 1)^2 = " << 28.09 << " =?= " << f2 << "\n";
  std::cout << "(3.2 + 1)^2 = " << 17.64 << " =?= " << f3 << "\n";

  

  std::cout << "Test Polynom Evaluate : OK\n";
}



void TestPolynomSumSub() {
  std::vector<unsigned> degs {1, 2, 3, 4, 5};
  std::vector<int> coeffs {1, 2, 3, 4, 5};
  Polynom poly6('x', degs, coeffs);
  std::cout << "poly6 : \n" << poly6 << "\n\n\n";

  std::vector<unsigned> degs2 {6, 7, 8, 9, 10};
  std::vector<int> coeffs2 {6, 7, 8, 9, 10};
  Polynom poly7('x', degs2, coeffs2);
  std::cout << "poly7 : \n" << poly7 << "\n\n\n";
  std::cout << "poly6 + poly7 : \n" << poly6 + poly7 << "\n\n\n";
  std::cout << "-(poly6 + poly7) : \n" << -(poly6 + poly7) << "\n\n\n";

  std::cout << "Test Polynom Sum Sub : OK\n";
}


void TestPolynomMulDiv() {

  std::cout << "Test Polynom Mul Div : OK\n";
}


void TestAll () {
  //TestMonom();
  //TestPolynomSimple();
  TestPolynomEvaluate();
  //TestPolynomSumSub();
  //TestPolynomMulDiv();
}
