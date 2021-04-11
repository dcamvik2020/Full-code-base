#ifndef BIG_NUMBER_H
#define BIG_NUMBER_h

#include <iostream>
#include <vector>

class BigNumber {
private:
  std::vector<int> v;
public:
  BigNumber(const std::string & s);
  BigNumber& operator = (const BigNumber & other);
  ~BigNumber() {}
  
  bool isNull();


  BigNumber& operator += (const BigNumber & other);
  friend BigNumber operator + (const BigNumber & x, const BigNumber & y);

  friend std::ostream & operator << (std::ostream & os, const BigNumber & num);
};

bool operator < (const BigNumber & lhs, const BigNumber & rhs);


#endif
