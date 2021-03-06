#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

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
void AssertEqual(const T& t, const U& u,
    const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
	  func();
	  cerr << test_name << " OK" << endl;
	} catch (runtime_error& e) {
	  ++fail_count;
	  cerr << test_name << " fail: " << e.what() << endl;
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









int GetDistinctRealRootCount(double a, double b, double c) {
  // my implementations
  // GARANTED : a^2 + b^2 + c^2 > 0
  
  /// linear equation	
  if (a == 0) {
     if (b == 0) {
       return 0;
     }
     return 1;
  }	  

  /// quadradic equation
  int D = b*b - 4*a*c;
  if (D  < 0) {
    return 0;
  } else if (D == 0) {
    return 1;
  } else {
    return 2;
  }
}

void TestGetDistinctRealRootCount() {
    AssertEqual(GetDistinctRealRootCount(1, 2, 1)  , 1, "1  test");
    AssertEqual(GetDistinctRealRootCount(1, 3, 2)  , 2, "2  test");
    AssertEqual(GetDistinctRealRootCount(1, -2, 1) , 1, "3  test");

    AssertEqual(GetDistinctRealRootCount(0, 3, 2)  , 1, "4  test");
    AssertEqual(GetDistinctRealRootCount(1, 0, 1)  , 0, "5  test");
    AssertEqual(GetDistinctRealRootCount(1, 0, -1) , 2, "6  test"); 
    AssertEqual(GetDistinctRealRootCount(1, 1, 1)  , 0, "7  test"); 

    AssertEqual(GetDistinctRealRootCount(1, 0, 0)  , 1, "8  test");
    AssertEqual(GetDistinctRealRootCount(0, 0, 2)  , 0, "9  test");
    AssertEqual(GetDistinctRealRootCount(0, 2, 0)  , 1, "10 test");

}

int main() {
  TestRunner runner;
  runner.RunTest(TestGetDistinctRealRootCount, "GetDistinctRealRootCount");
  return 0;
}

