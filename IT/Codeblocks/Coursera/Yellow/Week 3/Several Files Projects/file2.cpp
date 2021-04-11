/// This file is given to us as "phone_number.h"
/// #include "phone_number.h"
/// but my file has name "file2.h"
#include "file2.h"
#include <sstream>
#include <algorithm>
#include <exception>

/// Allowed to have in number all chars, even another '-' after the second '-' 
PhoneNumber::PhoneNumber (const string & international_number) {
  
  /// 1 check : '+'
  auto plus = international_number.find('+');
  if (plus == string::npos) {
    throw invalid_argument("Wrong format of number : without + at the beginning");
  }
  
  /// 2 check : '-'
  auto first_minus = international_number.find('-');
  if (first_minus == string::npos) {
    throw invalid_argument("Wrong format of number : city_code_, local_number_ are empty");
  } 
  if (first_minus == plus + 1) {
    throw invalid_argument("Wrong format of number : country_code_ is empty");
  }

  /// 3 check: the second '-' 
  auto second_minus = international_number.find('-', first_minus + 1);
  if (second_minus == string::npos) {
    throw invalid_argument("Wrong format of number : local_number_ is empty");
  } 
  if (second_minus == first_minus + 1) {
    throw invalid_argument("Wrong format of number : city_code_ is empty");
  }

  /// get codes
  
  country_code_ = international_number.substr(1, first_minus - 1);
  city_code_    = international_number.substr(first_minus + 1, second_minus - first_minus - 1);
  local_number_ = international_number.substr(second_minus + 1);
}




string PhoneNumber::GetCountryCode() const {return country_code_;}
string PhoneNumber::GetCityCode() const {return city_code_;}
string PhoneNumber::GetLocalNumber() const {return local_number_;}
string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

