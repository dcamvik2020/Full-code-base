#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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




void TestClass();

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestClass, "TestClass");
  return 0;
}

/*
class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};
*/








struct PersonInYear {
    //int year;
    bool changed; /// 0 - name, 1 - surname
    string name;
    string surname;
};

class Person {
public:
    /// no more than 1 change(name, surname) per year
    void ChangeFirstName(int year, const string& first_name) {             ///
        if (history.size() == 0) min_year = year;                          /// This is quite non-afficient
        if (year < min_year) min_year = year;                              /// we can use only change of @NAME
        if (year > max_year) max_year = year;                              /// the same situation with @SURNAME
                                                                           ///
        for (int tmp_year = year; tmp_year >= min_year; --tmp_year) {      /// also we can no use the flag @changed and @min_year, @max_year
            if (history.count(tmp_year) > 0) {                             /// and instead of one map we can use 2 maps
                history[year].surname = history[tmp_year].surname;         /// for names and surnames
                break;                                                     ///
            }                                                              /// as a result program will be much shorter
        }                                                                  ///
        history[year].name = first_name;                                   /// IT IS NOT VERY IMPORTANT TO MAKE 1/2 ACTIONS INSTEAD OF ALL ACTIONS
        history[year].changed = 0;

        /// we need to change also future information
        /// in years befor next change in name
        for (int tmp_year = year + 1; tmp_year <= max_year; ++tmp_year) {
            if (history.count(tmp_year) > 0) {
                if (history[tmp_year].changed == 0) {
                    break;
                } else {
                    history[tmp_year].name = first_name;
                }
            }
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (history.size() == 0)  min_year = year;
        if (year < min_year) min_year = year;
        if (year > max_year) max_year = year;

        for (int tmp_year = year; tmp_year >= min_year && history.find(year) == end(history); --tmp_year) {
            if (history.count(tmp_year) > 0) {
                history[year].name = history[tmp_year].name;
                break;
            }
        }
        history[year].surname = last_name;
        history[year].changed = 1;

        /// we need to change also future information
        /// in years befor next change in name
        for (int tmp_year = year + 1; tmp_year <= max_year; ++tmp_year) {
            if (history.count(tmp_year) > 0) {
                if (history[tmp_year].changed == 1) {
                    break;
                } else {
                    history[tmp_year].surname = last_name;
                }
            }
        }
    }
    string GetFullName(int year) {
        string res;
        
	if (history.size() == 0) {
           return "Incognito";
	}
	
	for (; year > min_year && history.find(year) == end(history); --year);
        if (history.count(year) == 0 ) {
            res = "Incognito";
        }
        else
        if (history[year].name != "" && history[year].surname != "") {
            res = history[year].name + " " + history[year].surname;
        }
        else
        if (history[year].name == "" && history[year].surname != "") {
            res = history[year].surname + " with unknown first name";
        }
        else
        if (history[year].name != "" && history[year].surname == "") {
            res = history[year].name + " with unknown last name";
        }
        return res;
    }
    //void print() {
    //    for (auto & event : history) {
    //        cout <<  "        " << event.first << " : " << event.second.name << " " << event.second.surname << endl;
    //    }
    //}
private:
    int min_year, max_year;
    map<int, PersonInYear> history;
};




void TestClass() {
  
  {
    Person person;
    AssertEqual(person.GetFullName(1904), "Incognito", "1 test");
  }

  {
    Person person;
    person.ChangeLastName(1901, "Pupkin");
    AssertEqual(person.GetFullName(1904), "Pupkin with unknown first name", "2 test");
  }

  {
    Person person;
    person.ChangeFirstName(1900, "Vasya");
    AssertEqual(person.GetFullName(1904), "Vasya with unknown last name", "3 test");
  }
  
  {
    Person person;
    person.ChangeFirstName(1900, "Vasya");
    person.ChangeLastName(1903, "Pupkin");
    AssertEqual(person.GetFullName(1904), "Vasya Pupkin", "4 test");
  }
}
