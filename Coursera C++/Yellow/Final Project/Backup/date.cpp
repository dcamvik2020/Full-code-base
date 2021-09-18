#include "date.h"

Date::Date(const string& date) {
    try {
        IsDate(date);
    } catch (invalid_argument& invarg) {
        throw invarg;
    }
}

/// Note: parts of the date aren't empty
void Date::IsDate(const string& s) {

    /// check only correct format (!= correct date)
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

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}


bool operator <= (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() <= rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}


bool operator >  (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() > rhs.GetDay();
        }
        return lhs.GetMonth() > rhs.GetMonth();
    }
    return lhs.GetYear() > rhs.GetYear();
} 


bool operator >= (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() >= rhs.GetDay();
        }
        return lhs.GetMonth() > rhs.GetMonth();
    }
    return lhs.GetYear() > rhs.GetYear();
}


bool operator == (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() == rhs.GetDay();
        }
    }
    return false;
}


bool operator != (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() != rhs.GetDay();
        }
    }
    return true;
}


ostream& operator << (ostream& os, const Date& date) {
  return os << setw(4) << setfill('0') << date.GetYear() << "-"
	    << setw(2) << setfill('0') << date.GetMonth() << "-"
	    << setw(2) << setfill('0') << date.GetDay();
}


ostream& operator << (ostream& os, const pair<Date, string>& p) {
  return os << p.first << " " << p.second;
}


Date ParseDate(istream & is) {
    string date_string;
    is >> date_string;
    return Date(date_string);
}
