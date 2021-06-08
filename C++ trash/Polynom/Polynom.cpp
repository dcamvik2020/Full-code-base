#include "Polynom.h"

Polynom::Polynom(char _var, const Monom & monom) : var(_var) {
  if (monom.getCoeff()) {
    monoms.push_back(monom);
  }
}



Polynom::Polynom (char _var, std::vector<unsigned> degs, std::vector<int> coeffs) : var(_var) {
  if (degs.size() != coeffs.size()) {
    throw std::invalid_argument("error : different sizes of degs and coefficents vectors");
  }
  for (unsigned i = 0; i < degs.size(); ++i) {
    if (coeffs[i]) {
      monoms.push_back(Monom(var, degs[i], coeffs[i])) ;
    }
  }
  std::sort(monoms.begin(), monoms.end(), [](const Monom & lhs, const Monom & rhs) {return lhs.getDeg() > rhs.getDeg();});
}



Polynom::Polynom (const Polynom & other) : var(other.getVar()) { 
  monoms = other.getMonoms();
}



Polynom & Polynom::operator = (const Polynom & rhs) {
  var = rhs.getVar();
  monoms = rhs.getMonoms();
  return *this;
}



Polynom operator + (const Polynom & lhs, const Polynom & rhs) {
  Polynom sum = lhs;
  return sum += rhs;
}

Polynom operator - (const Polynom & lhs, const Polynom & rhs) {
  Polynom sub = lhs;
  return sub -= rhs;
}

/*
Polynom operator * (const Polynom & lhs, const Polynom & rhs) {
  Polynom mul = lhs;
  return mul *= rhs;
}

Polynom operator / (const Polynom & lhs, const Polynom & rhs) {
  Polynom div = lhs;
  return div *= rhs;
}
*/

Polynom & Polynom::operator += (const Polynom & rhs) {
  if (var != rhs.getVar()) {
    throw std::invalid_argument("error : +/- of polynoms with different variables");
  }

  unsigned len = monoms.size();
  std::vector<Monom> monoms_r = rhs.getMonoms();
  unsigned len_r = monoms_r.size();
  std::vector<Monom> new_monoms;
  
  /// here the sum of 2 polynoms is gotten
  /// compare monoms and create new_monoms
  for (unsigned i = 0, j = 0; i < len || j < len_r; ) {
    if (i == len) {
      new_monoms.push_back(monoms_r[j]);
      ++j;
    } else if (j == len_r) {
      new_monoms.push_back(monoms[i]);
      ++i;
    } else {
      unsigned deg_l = monoms[i].getDeg();
      unsigned deg_r = monoms_r[j].getDeg();
      int coeff_l = monoms[i].getCoeff();
      int coeff_r = monoms_r[j].getCoeff();
      Monom tmp;
      if (deg_l > deg_r) {
        tmp = Monom(var, deg_l, coeff_l);
	++i;
      } else if (deg_l < deg_r) {
        tmp = Monom(var, deg_r, coeff_r);
	++j;
      } else {
        tmp = Monom(var, deg_l, coeff_l + coeff_r);
	++i;
       	++j;
      }
      
      if (tmp.getCoeff()) {
        new_monoms.push_back(tmp);
      }
    }
  }
  monoms = new_monoms;  
  return *this;
}

Polynom & Polynom::operator -= (const Polynom & rhs) {
  return *this += -rhs;
}

/*Polynom & Polynom::operator *= (const Polynom & rhs) {
  return *this;
}

Polynom & Polynom::operator /= (const Polynom & rhs) {
  return *this;
}
*/


std::ostream & operator << (std::ostream & os, const Polynom & p) {
  os << "Polynom with variable \"" << p.getVar() << "\" in format (deg, coeff)\n";
  bool first = true;
  const auto & monoms = p.getMonoms();
  for (const auto & monom : monoms) {
    if (first == false) os << ", ";
    os << monom; 
    first = false;
  }
  return os;
}


Polynom operator - (const Polynom & rhs) {
  Polynom neg_copy = rhs;
  for (auto & monom : neg_copy.getMonoms()) {
    monom = -monom;
  }
  return neg_copy;
}

