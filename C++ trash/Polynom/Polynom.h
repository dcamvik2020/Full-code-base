#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> /// for sort monoms by deg

#include "Monom.h"
/// vector <--> map  ??? better ??

class Polynom {
private:
  char var;
  std::vector<Monom> monoms;
public:
  Polynom (char _var = 'x', const Monom & monom = Monom());
  Polynom (char _var, std::vector<unsigned> degs, std::vector<int> coeffs);
  Polynom (const Polynom & other);

  Polynom & operator = (const Polynom & rhs);
  
  char getVar () const {return var;}
  std::vector<Monom> & getMonoms () {return monoms;}
  const std::vector<Monom> & getMonoms () const {return monoms;}

  friend Polynom operator + (const Polynom & lhs, const Polynom & rhs);
  friend Polynom operator - (const Polynom & lhs, const Polynom & rhs);

  friend Polynom operator * (const Polynom & lhs, const Polynom & rhs);
  friend Polynom operator / (const Polynom & lhs, const Polynom & rhs);


  Polynom & operator += (const Polynom & rhs);
  Polynom & operator -= (const Polynom & rhs);
  
  Polynom & operator *= (const Polynom & rhs);
  Polynom & operator /= (const Polynom & rhs);
  
  friend Polynom operator - (const Polynom & rhs);  

  friend std::ostream & operator << (std::ostream & os, const Polynom & p);

  ~Polynom () {}
};

template <typename T>
T evaluate (const Polynom & p, const T & value) {
  T res = 0, tmp = 1;
  unsigned cur_deg = 0;
  std::vector<Monom> monoms = p.getMonoms();
  unsigned len = monoms.size();
  for (unsigned i = len - 1; i >= 0; --i) {
    for ( ; cur_deg < monoms[i].getDeg(); ++cur_deg, tmp *= value);
    res += tmp * monoms[i].getCoeff();
    if (i == 0) break;
  }
  return res;
}

