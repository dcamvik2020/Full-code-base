#include <iostream>
#include <fstream>
#include "Factory.h"
#include "parser.h"

int main ()
{
  Factory factory("Company");
  std::fstream file("company.xml");
  
  if (file.is_open() == false) {
    std::cout << "Error : file isn't open!\n";
	return 0;
  }

  parse(factory, file);
  file.close();

/*
  Employee e1("e1", "prog", 100), e2("e2", "manager", 200), e3("e3", "pr", 300), e4("e4", "p", 400);
  Department d1("d1"), d2("d2");

  d1.addEmployee(e1);
  d1.addEmployee(e2);
  d2.addEmployee(e3);
  d2.addEmployee(e4);

  factory.addDepartment(d1);
  factory.addDepartment(d2);
*/
  std::cout << factory << "\n";
  return 0;
}
