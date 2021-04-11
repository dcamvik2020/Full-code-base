#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};










bool CorrectIsPalindrom(const string& str) {
  for(unsigned i = 0; i < str.size() / 2; ++i) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
bool IsPalindrom(const string & s) {
  for (unsigned i = 0; i < s.size() / 2; ++i) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }
  return true;
}




void TestEmptyString() {
  string str;
 
  str = "";
  Assert(IsPalindrom(str), "test empty, part 1");
  str = " ";
  Assert(IsPalindrom(str), "test empty, part 2");
  str = "  ";
  Assert(IsPalindrom(str), "test empty, part 3");
}

void TestOneLetter() {
  string str;
 
  str = "m";
  Assert(   IsPalindrom(str) , "1 letter test, part 1");
  str = "m   ";
  Assert( !(IsPalindrom(str)), "1 letter test, part 2");
  str = "   m";
  Assert( !(IsPalindrom(str)), "1 letter test, part 3");

}

void TestOneWord() {
  string str;

  str = "ab";
  Assert( !(IsPalindrom(str)), "1 word test, part 1");
  str = "mada";
  Assert( !(IsPalindrom(str)), "1 word test, part 2");
  str = "madam";
  Assert(   IsPalindrom(str) , "1 word test, part 3");
  str = "madam  ";
  Assert( !(IsPalindrom(str)), "1 word test, part 4");
  str = "wasitacaroracatisaw";
  Assert(IsPalindrom(str), "1 word test, part 5");
}

void TestForNotFullReading() {
  /// Garanted : the word isn't read fully ---> try
  ///            to find test where it is important
  string str;
 
  str = "madam madam";
  Assert(IsPalindrom(str), "not full reading test, part 1");
  str = "_madam";
  Assert( !(IsPalindrom(str)), "not full reading test, part 2");
  str = "madam_";
  Assert( !(IsPalindrom(str)), "not full reading test, part 3");
}




/*void Compare_Correct_Func_WithGiven_Func() {
 srand(time(NULL));
 string s(10, 0);
 

 for (unsigned i = 0; i < 10000; ++i) {
   for (unsigned j = 0; j < 10; ++j) { 
     s[j] = rand() % 128;
   }
   //s = "ab";
   cout << s << endl;
   AssertEqual(CorrectIsPalindrom(s), IsPalindrom(s), "some test");
 }

}*/

void TestPalindrom() {
  TestEmptyString();
  TestOneLetter();
  TestOneWord();
  TestForNotFullReading();
  //Compare_Correct_Func_WithGiven_Func();
}

int main() {
  TestRunner runner;
  runner.RunTest(TestPalindrom, "TestPalindrom");
  return 0;
}
