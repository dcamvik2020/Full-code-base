#pragma once

#include <exception>
//#include <iostream>
#include <sstream>

using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(const string& date) {
        try {
            IsDate(date);
        } catch (invalid_argument& invarg) {
            throw invarg;
        }
    }

    void  IsDate(const string& s) {
        /// check only correct format (!= correct date)
        /// Note: parts of the date aren't empty

        bool CorrectFormat = false;
        stringstream ss(s);
        ss >> year;

        /// it is better to check errors of operator >> (the call of fail())
        if (ss.fail() == false && ss.peek() == '-') {
            ss.ignore(1);
            ss >> month;
            if (ss.fail() == false && ss.peek() == '-') {
                ss.ignore(1);
                ss >> day;
                if (ss.fail() == false && ss.peek() == EOF) {
                    /// peek(): next char after date / EOF ---> tries to read ---> can
                    /// change the failbit
                    /// fail(): was ... read or not (doesn't change the failbit)

                    /// !!! fail && peek            /// fail() after "ss >> day"
                    /// not peek && fail            /// gives us current failbit

                    /// fail() after peek() ---> may get new failbit, not needed
                    CorrectFormat = true;
                }
            }
        }
        if (CorrectFormat == false) {
            throw invalid_argument("Wrong date format: " + s);
        }

        /// Check Correct Date (any year; not any day, month)
        if (month < 1 || 12 < month) {
            throw invalid_argument("Month value is invalid: " + to_string(month));
        } else if (day < 1  || 31 < day) {
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }
    }

    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}

};


bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}


