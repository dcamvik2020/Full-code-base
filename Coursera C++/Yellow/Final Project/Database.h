#pragma once

#include <iostream>
#include <map>
#include <set>

#include "Date.h"

using namespace std;

class Database {
private:
    map<Date, set<string>> DATABASE;
public:
    void AddEvent(const Date& date, const string& event) {
        DATABASE[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (DATABASE.count(date) > 0) {
            if (DATABASE.at(date).count(event) > 0) {
                DATABASE[date].erase(event);
                cout << "Deleted successfully" << endl;
                return true;
            }
        }
        cout << "Event not found" << endl;
        return false;
    }

    int DeleteDate(const Date& date) {
        if (DATABASE.count(date) > 0) {
            int N = DATABASE.at(date).size();
            DATABASE.at(date).clear();
            cout << "Deleted " << N << " events" << endl;
            return N;
        } else {
            cout << "Deleted 0 events" << endl;
            return 0;
        }
    }

    /*set<string>*/
    void Find(const Date& date) const {
        if (DATABASE.count(date) > 0) {
            for (const auto& event : DATABASE.at(date)) {
                cout << event << endl;
            }
        }
    }
    void Print() const {
        for (const auto& item : DATABASE) {
            for (const auto& event : item.second) {
                cout << setw(4) << setfill('0') << item.first.GetYear() << "-"
                     << setw(2) << setfill('0') << item.first.GetMonth() << "-"
                     << setw(2) << setfill('0') << item.first.GetDay() << " "
                     << event << endl;
            }
        }
    }
};

