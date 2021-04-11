#include <iostream>
#include <map>

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
    /*void print() {
        for (auto & event : history) {
            cout <<  "        " << event.first << " : " << event.second.name << " " << event.second.surname << endl;
        }
    }*/
private:
    int min_year, max_year;
    map<int, PersonInYear> history;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    //person.print(); cout << endl << endl;
    person.ChangeLastName(1967, "Sergeeva");
    //person.print(); cout << endl << endl;
    for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;

    }

    person.ChangeFirstName(1970, "Appolinaria");
    //person.print(); cout << endl << endl;
    for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    //person.print(); cout << endl << endl;
    for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
    }

    return 0;
}

