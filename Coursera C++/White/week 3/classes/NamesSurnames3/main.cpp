#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string SeperateFromArray (int year, map<int, string> m) {
    int len;
    string res, prev_name = "";
    vector<string> v;
    /// copy from map to vector<string> without copies
    for (const auto & item : m) {
        if (item.first <= year && item.second != "" && item.second != prev_name &&
            ((count(begin(v), end(v), item.second) == 0) ||
                     (v.size() > 1 && item.second == m[year]))) {
            v.push_back(item.second);
            prev_name = item.second;
        }
    }

    ///print new_name
    len = v.size();
    if (len) {
        res = v[len - 1];
        //cout << res << endl;
    }

    /// add old_names
    if (len > 1) {
        res += " (";
        for (int i = len - 2; i; --i) {
           res += v[i] + ", ";
        }
        res += v[0] + ")";
    }
    return res;
}


string FindNameByYear(const map<int, string>& names, int year) {
  string name;
  for (const auto& item : names) {
    if (item.first <= year) {
      name = item.second;
    } else {
      break;
    }
  }
  return name;
}

class Person {
public:
    Person(const string& name, const string& surname, const int& date) {
        birth = date;
        first_names[birth] = name;
        last_names[birth] = surname;
    }

  void ChangeFirstName(int year, const string& first_name) {
    if (year >= birth) {
        first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth) {
        last_names[year] = last_name;
    }
  }
  string GetFullName(int year) const {
    if (year < birth) {
        return "No person";
    }
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    } else {
      return first_name + " " + last_name;
    }
  }

  string GetFullNameWithHistory(int year) const{
        /// format : new_name (old_names in reversed order, followed by commas) new_surname (old_surnames in reversed order, followed by commas)
    if (year < birth) {
        return "No person";
    }
    string res;
    int names_before_year = 0, surnames_before_year = 0;
    for (auto& item : first_names) {
        if (item.first <= year) {
            ++names_before_year;
        }
    }
    for (auto& item : last_names) {
        if (item.first <= year) {
            ++surnames_before_year;
        }
    }
    if (names_before_year==0 && surnames_before_year==0) {
        return "Incognito";
    } else if (names_before_year==0) {
        res = SeperateFromArray(year, last_names);
        res += " with unknown first name";
    } else if (surnames_before_year==0) {
        res = SeperateFromArray(year, first_names);
        res += " with unknown last name";
    } else {
        res = SeperateFromArray(year, first_names);
        res += " ";
        res += SeperateFromArray(year, last_names);
    }
    return res;
  }

private:
  int birth;
  map<int, string> first_names;
  map<int, string> last_names;
};



int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
