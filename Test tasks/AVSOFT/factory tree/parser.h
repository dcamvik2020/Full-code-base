#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Factory.h"

void parse_employment (Employee & emp, std::istream & in);

void parse_department (Department & dep, std::istream & in);

void parse (Factory & factory, std::istream & in);

#endif  /// PARSER_H
