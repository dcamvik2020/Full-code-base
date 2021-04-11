#pragma once

// Simple calculator :
//   # operations : +, -, *, /, unary + and -, ^ degree 
//   # WITHOUT parentheses (, )
//   # number type : int
//   # garanted : the result may be represented as an int number

// Advanced calculator :
//   # operations : 


#include <iostream>
#include <exception>
#include "term.h"

// Simple calculator
int CalcArithmExpr(const char * expr);

// Advanced calculator
int Compute(const char * expr);
