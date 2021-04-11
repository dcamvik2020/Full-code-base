#include "BigNumber.h"

BigNumber::BigNumber(const std::string & s) {
  for (size_t i = s.size() - 1; i > 8; i -= 9) {
    v.push_back( atoi ((s.substr(i - 9, 9)).c_str());
  }
  v.push_back( atoi ((s.substr(0, s.size() % 9)).c_str()) );
  if (v.size() == 0) {
    v.push_back(0);
  }
}


BigNumber& BigNumber::operator = (const BigNumber & other) {
  v = other.v;
  return *this;
}

bool BigNumber::isNull() {
  if (v.size() == 1 && v[0] == 0) return true;
  for (auto x : v) {
    if (x) return false;
  }
  return true;
}

BigNumber& BigNumber::operator += (const BigNumber & other) {
  if (other.isNull() == true) return *this;
  if (this->isNull() == true) {
    *this = other;
    return *this;
  }


  std::vector<int> tmp(std::max(v.size(), other.v.size()) + 1, 0);
  long rest = 0;
  for (size_t i = 0; i < tmp.size(); ++i) {
    ;
  }
}


BigNumber operator + (BigNumber x, const BigNumber & y) {
  return x += y;
}


std::ostream & operator << (std::ostream & os, const BigNumber & num) {
  for (int x : num.v) os << x;
  return os;
}

bool operator < (const BigNumber & lhs, const BigNumber & rhs) {
  for (size_t i = 0; 1 ; ++i) {
    if ();
  }
}
