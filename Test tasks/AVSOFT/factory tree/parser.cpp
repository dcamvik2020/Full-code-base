
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "parser.h"

void parse_employment (Employee & emp, std::istream & in) {
  std::string line;
  std::string name, function, salary;
  while (getline(in, line)) {           /// <tag>Contents</tag>
    std::stringstream ss(line); /// get rid of
	std::string tag;            /// spaces in ss
	ss >> tag;                  /// by using tag

	if (tag == "</employment>") break;
	
	if (tag.substr(0, 9) == "<surname>") 
	  name = tag.substr(9, tag.size() - 10 - 9), std::cout << name << "   " << name.size() << "       ";
	else 
	if (tag.substr(0, 6) == "<name>") 
	  name += " " + tag.substr(6, tag.size() - 7 - 6), std::cout << name << "   " << name.size() << "       ";
	else 
	if (tag.substr(0, 12) == "<middleName>")
	  name += " " + tag.substr(12, tag.size() - 13 - 12), std::cout << name << "   " << name.size() << "       \n";
    else 
	if (tag.substr(0, 10) == "<function>") {
	  function = tag;
	  while (ss >> tag) function += " " + tag;
	  function = function.substr(10, function.size() - 11 - 10);
	}
	else
	if (tag.substr(0, 8) == "<salary>")
	  salary = tag.substr(8, tag.size() - 9 - 8);
  }
  /// TODO : name has usually wrong size ... i.g. actual size = 48 when should be 25 ...
  //std::cout << "|" << name << "|\t" << name.size() << "\n";
  emp.setName(std::string(name.c_str()));
  emp.setPosition(function);
  emp.setSalary(atol(salary.c_str()));
}

void parse_department (Department & dep, std::istream & in) {
  std::string line;
  while (getline(in, line)) {
    std::stringstream ss(line);
    std::string tag;
	ss >> tag;

	if (tag == "</department>") break;
	if (tag == "<employment>") {
      Employee emp("");
	  parse_employment (emp, in);
	  dep.addEmployee(emp);
	}
  }
}

void parse (Factory & factory, std::istream & in) {
  std::string line;

  while (getline(in, line))
  {
    std::stringstream ss(line);
	std::string tag;
	ss >> tag;

	if (tag == "<department") /// it's a part of line
	{
      std::string name;
	  getline(ss, name); /// name="...">
	  name = name.substr(7);
	  unsigned pos;
	  std::cout << "name = " << name << "\n";
	  for (pos = name.size() - 1; name[pos] != '\"'; --pos);
	  name.resize(pos);

	  Department dep(name);
      parse_department(dep, in);
	  factory.addDepartment(dep);
	} 
  }
}

