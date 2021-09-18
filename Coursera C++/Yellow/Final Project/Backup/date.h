#pragma once

#include <exception>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int year_0, int month_0, int day_0)
	    : year(year_0), month(month_0), day(day_0) {}
    Date(const string& date);

    /// Note: parts of the date aren't empty
    void  IsDate(const string& s);

    int GetYear() const {return year;}
    int GetMonth() const {return month;}
    int GetDay() const {return day;}

};

bool operator <  (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator >  (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);

ostream& operator << (ostream& os, const Date& date);
ostream& operator << (ostream& os, const pair<Date, string>& p);

Date ParseDate(istream & is);
