#include <iostream>
#include "file2.h"

int main() {
  try {
    PhoneNumber s("+7-495-111-22-33");
    cout << s.GetInternationalNumber() << "     OK" << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }


  try {
    PhoneNumber s("+7-495-1112233");
    cout << s.GetInternationalNumber() << "     OK"  << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }


  try {
    PhoneNumber s("+323-22-460002");
    cout << s.GetInternationalNumber() << "     OK"  << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }


  try {
    PhoneNumber s("+1-2-coursera-cpp");
    cout << s.GetInternationalNumber() << "     OK"  << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }


  try {
    PhoneNumber s("1-2-333");
    cout << s.GetInternationalNumber() << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }

  try {
    PhoneNumber s("+7-1233");
    cout << s.GetInternationalNumber() << endl;
  } catch (invalid_argument & e) {
    cerr << e.what() << endl;
  }


  return 0;
}
