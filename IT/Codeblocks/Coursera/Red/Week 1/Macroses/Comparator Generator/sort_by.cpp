#include "airline_ticket.h"
#include <iomanip>
//#include "../test_runner.h" /// for me
#include "test_runner.h" /// for their test system

#include <algorithm>
#include <numeric>
using namespace std;

//Date::Date(int cur_year, int cur_month, int cur_day)             /// IT DOESN'T WORK ... WE CAN JUST
//  : year(cur_year), month(cur_month), day(cur_day) {}            /// WRIGHT LOWER : Date(1200, 3, 1)

bool operator < (const Date & lhs, const Date & rhs) {
  if (lhs.year == rhs.year) {
    if (lhs.month == rhs.month) {
      return lhs.day < rhs.day;
    }
    return lhs.month < rhs.month;
  }
  return lhs.year < rhs.year;
}

bool operator == (const Date & lhs, const Date & rhs) {
  if (lhs.year == rhs.year) {
    if (lhs.month == rhs.month) {
      return lhs.day == rhs.day;
    }
  }
  return false;
}

ostream & operator << (ostream & os, const Date & date) {
  return os << setw(4) << setfill('0') << date.year << "-"
            << setw(2) << setfill('0') << date.month << "-"
            << setw(2) << setfill('0') << date.day;
}

//Time::Time(int cur_hours, int cur_minutes)                       /// IT DOESN'T WORK ... WE CAN JUST
//  : hours(cur_hours), minutes(cur_minutes) {}                    /// WRIGHT LOWER : Time(8, 30)

bool operator < (const Time & lhs, const Time & rhs) {
  if (lhs.hours == rhs.hours) {
    return lhs.minutes < rhs.minutes;
  }
  return lhs.hours < rhs.hours;
}

ostream & operator << (ostream & os, const Time & time) {
  return os << time.hours << ":" << time.minutes;
}

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define SORT_BY(field)              \
  [] (const AirlineTicket& lhs,     \
      const AirlineTicket& rhs) {   \
    return lhs.field < rhs.field;   
  }

void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
