#include <iostream>
#include <fstream>
#include <sstream>

#include "Employee.h"
#include <string>
#include <iomanip>

Employee::Employee (const std::string & name,
                    const std::string & pos, unsigned sal)
              : fullname(name), position(pos), salary(sal) {}

std::string Employee::getName () const {
  return fullname;
}

std::string Employee::getPosition () const {
  return position;
}

unsigned Employee::getSalary () const {
  return salary;
}

void Employee::setName (const std::string & name) {
  fullname = name;
}

void Employee::setPosition (const std::string & pos) {
  position = pos;
}

void Employee::setSalary (unsigned sal) {
  salary = sal;
}

std::ostream & operator << (std::ostream & os, const Employee & e) {
  constexpr unsigned name_position_width = 40;
  const unsigned spaces_name = name_position_width - e.getName().size();
  const unsigned spaces_position = name_position_width - e.getPosition().size();
  constexpr unsigned salary_width = 15;
  const unsigned spaces_salary = salary_width - std::to_string(e.getSalary()).size();

  std::cout << "e.getName().size() = " << e.getName().length() << "\n";
  std::cout << "e.getName() = |";
  unsigned counter = 0;
  for (char c : e.getName())
  {  
    std::cout << c;
	counter++;
  }
  std::cout << "|\t\t counter = " << counter << "\n";
  std::cout << "spaces_name = " << spaces_name << "\n";
  std::cout << "spaces_position = " << spaces_position << "\n";
  os << e.getName() << std::string(spaces_name, ' ');
  os << e.getPosition() << std::string(spaces_position, ' ');
  return os << e.getSalary() << std::string(spaces_salary, ' ') << " (RUB)";
}

bool operator < (const Employee & lhs, const Employee & rhs) {
  return lhs.getName() < rhs.getName();
}
