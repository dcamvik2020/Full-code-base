#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

string GetNameByYear(const map<int, string> & m, int year) {
    auto it = m.upper_bound(year);
    if (it != m.begin()) {
        return prev(it) -> second;
    }
    /// it = m.begin() = history.begin() --> unknown name
    return "";
}

class Person {
public:
    /// no more than 1 change(name, surname) per year
    void ChangeFirstName(int year, const string& first_name) {
        names[year] = first_name; 
    }

    void ChangeLastName(int year, const string& last_name) {
        surnames[year] = last_name;
    }
    
    string GetFullName(int year) {
        /// operations of getting name and surname from maps by year --> similar --> function
        string name    = GetNameByYear(names   , year);
        string surname = GetNameByYear(surnames, year);

	if (name.empty() && surname.empty()) {
            return "Incognito";
	}
	if (name.empty()) {
            return surname + " with unknown first name";
	}
        if (surname.empty()) {
            return name + " with unknown last name";
	}
	return name + " " + surname;
    }
 
private:
    map<int, string> names;
    map<int, string> surnames;
};

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

