#include <iostream>
#include <fstream>
#include <sstream>

#include "Department.h"

#include <set>
#include <string>


void Department::countAverageSalary () {
    unsigned total_salary = 0;
    for (const auto & emp : employees) {
      total_salary += emp.getSalary(); 
    } 
    avg_salary = (double) total_salary / employees.size();
  } 
  

Department::Department (const std::string & _name)
        : name(_name), cnt_employees(0), avg_salary(0.0) {}
        
std::string Department::getName() const {
  return name;
}

void Department::setName(const std::string & _name) {
  name = _name;
}

const std::set<Employee> & Department::getEmployees () const {
  return employees;
}

std::set<Employee> & Department::getEmployees () {
  return employees;
}
  
unsigned Department::getNumberOfEmployees () const {
  return cnt_employees;
}

double Department::getAverageSalary () const {
  return avg_salary;
}
  
void Department::addEmployee (const Employee & emp) {
  employees.insert(emp);
}

void Department::removeEmployee (const std::string & emp_name) {
  for (auto & emp : employees) {
    if (emp.getName() == emp_name) {
      employees.erase(emp); 
    }
  }
} 

std::ostream & operator << (std::ostream & os, const Department & d) {
  for (const auto & emp : d.getEmployees())
    os << "\t" << emp << "\n";
  return os;
}

bool operator < (const Department & lhs, const Department & rhs) {
  return lhs.getName() < rhs.getName();
}
