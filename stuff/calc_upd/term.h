#pragma once

#include <iostream>
#include <exception>

class Term {
private:
  const char * start, * finish;	
  int value;
  // allows parantheses
  void Compute();
  // a simple arithmetic expression without parantheses and ^ operation
  int SimpleCompute(const char * start, const char * finish);
public:
  int Evaluate() const {return value;}
  
  // automatically calculates the value of expression with out parantheses
  Term(const char * start, const char * finish);
};
