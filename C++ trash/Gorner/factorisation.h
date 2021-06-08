#include <vector>

using vector_t = std::vector<size_t>;

class Monom {
private:
  char var;
  size_t deg;
  int coeff;
public:
  Monom() {}
  Monom(char var, const char * start, const char * finish) 
	  : var(var), deg(0), coeff(0) {
    Parse(start, finish);
  }
  void Parse(const char * start, const char * finish) {
    bool coeffSign = false, readVar = false;
    for (const char * ptr = start; int (finish - ptr); ++ptr) {
      if (*ptr == ' ' || *ptr == '^') continue;
      if (*ptr == '-') coeffSign = true;
      else if (*ptr == var) readVar = true;
      else if (readVar == false) {
        coeff *= 10;
        coeff += *ptr - '0';
      } else {
	deg *= 10;
        deg += *ptr - '0';
      }
    }
    if (coeffSign) coeff = -coeff;
  }
  size_t GetDeg() const {return deg;}
  size_t GetCoeff() const {return coeff;}
};

void GetDegsAndCoeffs(char var, const char* Polinom, vector_t & degs, vector_t & coeffs) {
  // get coefficents for degrees of variable
  const char *curTokenStart = Polinom;
  Monom tmp;
  for (const char* ptr = Polinom; *ptr; ) {
    // split for tokens (monoms)
    while (*ptr && *ptr != '+' && *ptr != '-') ++ptr;
    if (int(ptr - curTokenStart) == 0) {
      if (*ptr == '\0') break;
      ++ptr;
      continue;
    }
    tmp = Monom(var, curTokenStart, ptr);
    degs.push_back(tmp.GetDeg());
    coeffs.push_back(tmp.GetCoeff());
    curTokenStart = ptr;
  }
}
