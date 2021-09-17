/// Final Task Number 1
/// Task: to make a data base that interacts with
/// user through stdin-stdout.


/// DataBase: pairs (date, event)
/// date : year-month-day (integers)
/// event: not empty string without ' ';'\n';etc.


/// POSSIBLE: 1 date--->several DIFFERENT events
/// same events --> don't save


/// COMMANDS:
/// Add Date Event
/// Del Date Event
/// Del Date         -- ALL events for ONE date
/// Find Дата        -- ALL events for ONE date
/// Print            -- ALL events for ALL dates


/// GARANTED:
/// 1 cmd - 1 line (ignore empty strings)
/// ALL cmds are correct (look earlier)
/// ALL dates, events are not empty strings
/// ALL dates with negative years or ... will be deleted
///              so, they won't be printed
/// days in month : all consist of 31 days
/// year -- it can be negative, 0, positive


/// INPUT ERRORS:
/// unknown cmd --> print "Unknown command: cmd"
/// letters before or after date -- error
/// date fromat: "Wrong date format: DATE"
///              DATE -- was written by user
///              DATE: parts != "", but can be zero, even negative
/// if format is correct --> check month
///              month in [1, 12], else "Month value is invalid: MONTH"
/// if month us correct --> check day
///              day in [1, 31], else "Day value is invalid: DAY"


/// errors are in day && month --< only 1 message about error in month
///       1-1-1    correct
///      -1-1-1    correct
///      1--1-1    correct fromat, but incorrect   month=-1
///     1---1-1    incorrect fromat: month with "--" before number
///     1​-+1-+1    correct date


/// error --> print message --> exit(0) (STOP)

#include <exception>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <set>


using namespace std;

class Date {
public:
    Date(const string& date) {
        ///year
        try {
            IsDate(date);
        } catch (invalid_argument& invarg) {
            throw invarg;
        }
    }

    /*bool*/
    void  IsDate(const string& s) {
        /// Year-Month-Day, all are integers (not specified)
        /// correct format != correct date
        /// here we check only correct format

        /// Note: parts of the date aren't empty

        /// Check Correct Format
        //int year, month, day;
        bool CorrectFormat = false;
        stringstream ss(s);
        ss >> year;
        if (ss.fail() == false && ss.peek() == '-') {
            ss.ignore(1);
            ss >> month;
            if (ss.peek() == '-') {
                ss.ignore(1);
                ss >> day;
                ///return true; -- for format, not date
                if (ss.fail() == false && ss.peek() == EOF) {
                    /// peek(): existance of extra chars after date
                    /// fail(): was the day read or not

                    /// !!! fail && peek
                    /// not peek && fail

                    /// why?    peek() tries to read --> it can set
                    ///         failbit <---> it causes an error

                    /// if we call fail() after "ss >> day" we get the
                    /// current failbit

                    /// if we call fail() after peek() in "if (...)" we
                    /// change the failbit, so there might be errors

                    CorrectFormat = true;
                }
            }
        }
        if (CorrectFormat == false) {
            throw invalid_argument("Wrong date format: " + s);
        }

        /// Check Correct Date
        /// any number for year, but not for day, month
        if (month < 1 || 12 < month) {
            throw invalid_argument("Month value is invalid: " + to_string(month));
        } else if (day < 1  || 31 < day) {
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }
        //return true;
    }

    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        } else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}


class Database {
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
private:
    map<Date, set<string>> DATABASE;
};

int main() {
    Database db;
    string command;
    string cmd, date, event;
    //stringstream stream;
    while (getline(cin, command)) {
        //cout << "                ........ = " << command << endl;
        stringstream stream(command);

        if (stream.str() == "") {
            continue;
        }

        //stream << command;
        stream >> cmd;
        //cout << "                read cmd = " << cmd << endl;
        if (cmd == "Print") {
            db.Print();
        } else if (cmd == "Find") {
            try {
                stream >> date;
                /*set<string> eventsForDate = */ db.Find(Date(date));
            } catch (invalid_argument& invarg) {
                //cout << "Wrong date format: " << date << endl;
                cout << invarg.what() << endl;
                return 1;
            }
            /// print vector
        } else if (cmd == "Add") {
            try {
                stream >> date;
                stream >> event;
                //cout << "             try to come to Add()" << endl;
                db.AddEvent(date, event);
            } catch (invalid_argument& invarg) {
                //cout << "Wrong date format: " << date << endl;
                cout << invarg.what() << endl;
                return 2;
            }
            /// ...
        } else if (cmd == "Del") {
            try {
                stream >> date;
                stream >> event;
                ///if (stream.tellg() == -1) {     <---> wrong
                if (stream.fail() == true) {
                    /// didn't read event
                    db.DeleteDate(date);
                } else {
                    db.DeleteEvent(date, event);
                }
            } catch (invalid_argument& invarg) {
                //cout << "Wrong date format: " << date << endl;
                cout << invarg.what() << endl;
                return 3;
            }
            stream >> event;
        } else {
            cout << "Unknown command: " << cmd << endl;
        }
    }

    return 0;
}
