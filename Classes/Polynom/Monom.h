#pragma once

#include <iostream>
#include <tuple>

class Monom {
private:
  char var;
  unsigned deg;
  int coeff;
public:
  Monom () : var('-'), deg(0), coeff(0) {}
  Monom (char _var, unsigned _deg, int _coeff) : var(_var),  deg(_deg), coeff(_coeff) {}
  Monom (const Monom & other) : var(other.getVar()), deg(other.getDeg()), coeff(other.getCoeff()) {}

  char getVar () const {return var;}
  unsigned getDeg () const {return deg;}
  int getCoeff () const {return coeff;}

  void setDeg (unsigned _deg) {deg = _deg;}
  void setCoeff (int _coeff) {coeff = _coeff;}

  auto getMonom () const {return std::tie(var, deg, coeff);}

  Monom & operator = (const Monom & other) {
    std::tie(var, deg, coeff) = other.getMonom();
    return *this;
  }

  friend Monom operator + (const Monom & lhs, const Monom & rhs);
  friend Monom operator - (const Monom & lhs, const Monom & rhs);
  friend Monom operator * (const Monom & lhs, const Monom & rhs);
  friend Monom operator / (const Monom & lhs, const Monom & rhs);

  Monom & operator += (const Monom & rhs);
  Monom & operator -= (const Monom & rhs);
  Monom & operator *= (const Monom & rhs);
  Monom & operator /= (const Monom & rhs);

  friend Monom operator - (const Monom & rhs);

  friend std::ostream & operator << (std::ostream & os, const Monom & m);

  
  ~Monom () {}
};
