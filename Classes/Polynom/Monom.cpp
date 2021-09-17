
#include "Monom.h"

Monom operator + (const Monom & lhs, const Monom & rhs) {
  Monom sum = lhs;
  return sum += rhs;
}

Monom & Monom::operator += (const Monom & rhs) {
  if (var != rhs.getVar()) {
    throw std::invalid_argument("error : +/- of monoms with different variables");
  }
  if (deg != rhs.getDeg()) {
    throw std::invalid_argument("error : +/- of monoms with different degrees");
  }
  coeff += rhs.getCoeff();
  return *this;
}



Monom operator - (const Monom & rhs) {
  return Monom(rhs.getVar(), rhs.getDeg(), -rhs.getCoeff());
}

std::ostream & operator << (std::ostream & os, const Monom & m) {
  //return  os << "{ " << m.getVar() << " -> deg, coeff : "  << m.getDeg() << " , " << m.getCoeff() << " }";
  return  os << "{ " << m.getDeg() << " , " << m.getCoeff() << " }";
}
