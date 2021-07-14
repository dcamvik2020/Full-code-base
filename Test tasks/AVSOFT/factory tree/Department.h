#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.h"
#include <set>
#include <string>

class Department {
private:
  std::string name;
  unsigned cnt_employees;
  double avg_salary;
  std::set<Employee> employees; 

  void countAverageSalary ();
  
public:
  Department (const std::string & _name); 

  std::string getName() const;
  void setName (const std::string & _name);

  const std::set<Employee> & getEmployees () const;
  std::set<Employee> & getEmployees ();
  
  unsigned getNumberOfEmployees () const;
  double getAverageSalary () const;
  
  void addEmployee (const Employee & emp);
  void removeEmployee (const std::string & emp); 

  ~Department () {}
};

std::ostream & operator << (std::ostream & os, const Department & d);

bool operator < (const Department & lhs, const Department & rhs);

#endif   /// DEPARTMENT_H
