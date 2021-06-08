#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct PersonInYear {
    //int year;
    bool changed; /// 0 - name, 1 - surname
    string name;
    string surname;
};

class Person {
public:
    /// no more than 1 change(name, surname) per year
    void ChangeFirstName(int year, const string& first_name) {
        min_year = (history.size() == 0) ? (year) : (min(min_year, year));
        max_year = (history.size() == 0) ? (year) : (max(max_year, year));

	auto it = history.upper_bound(year);
	if (it != history.begin()) {
            history[year].surname = prev(it) -> second.surname;
	}
        history[year].name = first_name;
        history[year].changed = 0;

        /// we also need to change information in future years without changes in name
        for ( ; it != history.end(); ++it) {
            if (it -> second.changed == 0) {
                break;
            }
            it -> second.name = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        min_year = (history.size() == 0) ? (year) : (min(min_year, year));
        max_year = (history.size() == 0) ? (year) : (max(max_year, year));

        auto it = history.upper_bound(year);
	if (it != history.begin()) {
            history[year].name = prev(it) -> second.name;
	}
        history[year].surname = last_name;
        history[year].changed = 1;

        /// we also need to change information in future years without changes in surname
        for ( ; it != history.end(); ++it) {
            if (it -> second.changed == 1) {
                break;
            }
            it -> second.surname = last_name;
        }
    }
    
    string GetFullName(int year);
 
private:
    int min_year, max_year;
    map<int, PersonInYear> history;
};



string Person::GetFullName(int year) {
    if (history.size() == 0 || year < min_year) {
        return "Incognito";
    }

    /// get years from map (map --> sorted years)
    vector<int> all_years(history.size());
    unsigned i = 0;
    for (auto it = history.begin(); it != history.end(); ++it) {
        all_years[i++] = it -> first;
    }

    /// binary search in years (find : max(years : they <= year)) 
    auto info = history.upper_bound(year);
    if (info != history.begin()) {
        info = prev(info);
    }
    
    PersonInYear tmp = info -> second;
    if (tmp.name == "") {
        return tmp.surname + " with unknown first name";
    } else if (tmp.surname == "") {
        return tmp.name + " with unknown last name";
    } else {
        return tmp.name + " " + tmp.surname;
    }
}

int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}

