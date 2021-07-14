#ifndef FACTORY_H
#define FACTORY_H

#include "Department.h"
#include <string>

class Factory {
private:
  std::string name;
  std::set<Department> departments;

public:
  Factory (const std::string & _name);

  std::string getName () const;
  void setName (const std::string & _name);

  void addDepartment (const Department & d);
  void removeDepartment(const std::string & name) ;

  std::set<Department> & getDepartments ();
  const std::set<Department> & getDepartments () const;


  ~Factory () {}
};

std::ostream & operator << (std::ostream & os, const Factory & factory);

#endif   /// FACTORY_H
