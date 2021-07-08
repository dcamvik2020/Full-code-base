#include <iostream>

void Reverse(std::string & s) {
  for (size_t i = 0; i < s.size() / 2; ++i) {
    std::swap(s[i], s[s.size() - 1 - i]);
  }
}

std::string sum        (const std::string & a, const std::string & b);
std::string sub        (const std::string & a, const std::string & b);
std::string simple_mul (const std::string & a, char p);
std::string mul        (const std::string & a, const std::string & b);
std::string pow        (const std::string & a, size_t p);


int main() {
  /// 0 : get long number (1 digit --> from 0 to 255  -->   256 ~ 10)
  /// but now we want just keep it as "decimal string"	
  char op;
  std::string a, b, res;
  std::cin >> a >> op >> b;
  
  if (op == '+') {
    res = sum(a, b);
  } else if (op == '-') {
    res = sub(a, b);
  } else if (op == '*') {
    res = mul(a, b);
  } else if (op == '^') {
    res= pow(a, atoi(b.c_str()));
  }
  //for (size_t i = 0; i < 1'000'000; ++i) sum(a, b);
  std::cout << res << std::endl;
  
  return 0;
}

std::string sum(const std::string & a, const std::string & b) {
  int rest = 0;
  std::string res(std::max(a.size(), b.size()) + 1, 0);
  
  for (size_t k = 0; k < res.size(); ++k) {
	unsigned res_pos = res.size() - 1 - k;
    unsigned a_pos = a.size() - 1 - k;
    unsigned b_pos = b.size() - 1 - k;
    if (k >= a.size() && k >= b.size()) {
      res[res_pos] = rest + '0';
      rest = 0;
    } else if (k >= a.size()) {
      res[res_pos] = (b[b_pos] - '0' + rest) % 10 + '0';
      rest = (b[b_pos] - '0' + rest) / 10;
    } else if (k >= b.size()) {
      res[res_pos] = (a[a_pos] - '0' + rest) % 10 + '0';
      rest = (a[a_pos] - '0' + rest) / 10;
    } else {
      res[res_pos] = (a[a_pos]-'0' + b[b_pos]-'0' + rest) % 10 + '0';
      rest = (a[a_pos] - '0' + b[b_pos] - '0' + rest) / 10;
    }
  }
  
  if (res[0] == '0' && res.size() > 1) 
    res.erase(res.begin());
  return res;
}

std::string sub(const std::string & a, const std::string & b) {
  /// suppose that a, b without '0' in the beginning
  
  bool equal = (a.size() == b.size());
  bool greater = false;
  if (a.size() > b.size()) greater = true;
  if (a.size() == b.size()) {
    for (size_t i = 0; i < a.size(); ++i) {
      if (equal == false) break;  /// at this moment we know is 1st > 2nd or not
      greater = greater || (a[i] >  b[i]   && equal);
      equal   = equal   && (a[i] == b[i]);
    }
  }
  if (equal) return "0";
  if (greater == false) return "-" + sub(b, a);

  /// now we suppose that (a>b) ---> (a.len > b.len || a[0] > b[0])
  bool credit = false;
  std::string res(a.size(), 0);
  for (size_t k = 0; k < res.size(); ++k) {
    if (k >= b.size()) {
      res[res.size() - 1 - k] = a[a.size() - 1 - k] - credit;
      credit = false;
    } else {
      if (a[a.size() - 1 - k] - credit >= b[b.size() - 1 - k]) {
        res[res.size() - 1 - k] = a[a.size() - 1 - k] - credit - 
		                  b[b.size() - 1 - k] + '0';
	credit = false;
      } else {
        res[res.size() - 1 - k] = a[a.size() - 1 - k] - credit - 
		                  b[b.size() - 1 - k] + '0' + 10;
	credit = true;
      }
    }
  }
  return res;
}

std::string simple_mul(const std::string & a, char p) {
  int rest = 0, tmp;
  std::string res(a.size() + 1, 0);
  for (size_t k = 0; k < a.size(); ++k) {
    tmp = (a[a.size() - 1 - k] - '0') * (p - '0');
    res[res.size() - 1 - k] = (tmp + rest) % 10 + '0';
    rest                    = (tmp + rest) / 10; 
  }
  res[0] = rest + '0';
  return res;
}

std::string mul(const std::string & a, const std::string & b) {
  std::string res(a.size() + b.size(), '0');
  for (size_t k = 0; k < b.size(); ++k) {
    std::string tmp = simple_mul(a, b[b.size() - 1 - k]) + std::string(k, '0');
    //std::cout << "tmp : " << tmp << std::endl;
    res = sum(res, tmp);
  }
  return res;
}

std::string pow(const std::string & a, size_t p) {
  std::string res("1"), copy(a);
  while (p) {
    if (p % 2 == 0) {
      copy = mul(copy, copy);
      p /= 2;
    } else {
      res = mul(res, copy);
      p--;
    }
  }
  return res;
}
