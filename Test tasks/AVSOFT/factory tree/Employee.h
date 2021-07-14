#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
  std::string fullname;
  std::string position;
  unsigned salary;

public:
  Employee (const std::string & name,
            const std::string & pos = "", unsigned sal = 0);

  std::string getName () const;
  std::string getPosition () const;
  unsigned getSalary () const;

  void setName (const std::string & name);
  void setPosition (const std::string & pos);
  void setSalary (unsigned sal);

  
  ~Employee () {}
};

std::ostream & operator << (std::ostream & os, const Employee & e);

bool operator < (const Employee & lhs, const Employee & rhs);

#endif   /// EMPLOYEE_H
