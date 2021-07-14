#include "Factory.h"
#include <string>

Factory::Factory (const std::string & _name) : name(_name) {}

std::string Factory::getName () const {
  return name;
}

void Factory::setName (const std::string & _name) {
  name = _name;
}

void Factory::addDepartment (const Department & d) {
  departments.insert(d);
}

void Factory::removeDepartment(const std::string & name) {
  auto iter_to_remove = departments.find(name);
  if (iter_to_remove != departments.end()) {
    departments.erase(iter_to_remove);
  }
}

std::set<Department> & Factory::getDepartments () {
  return departments;
}

const std::set<Department> & Factory::getDepartments () const {
  return departments;
}

std::ostream & operator << (std::ostream & os, const Factory & factory) {
  os << std::string("Tree of factory:\n") << factory.getName() << std::string(":\n");
  for (const auto & d : factory.getDepartments()) {
    os << std::string("   ") << d.getName() << std::string(":\n");
	for (const auto & emp : d.getEmployees()) {
      os << std::string("      ") << emp << std::string("\n");
	}
	os << std::string("\n");
  }
  return os;
}
