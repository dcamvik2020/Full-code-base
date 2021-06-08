#include "database.h"

void Database::Add(const Date& date, const string& event) {
  if (DATABASE.count(date) > 0) {
    if (find(DATABASE[date].begin(), 
	     DATABASE[date].end(), event) != DATABASE[date].end()) {
      return;
    }
  }  
  DATABASE[date].push_back(event);
}


///______________________________________________________________________________________________________________


//template<class PredicateType>
vector<pair<Date, string>> 
Database::FindIf(function<bool(const Date& date, 
			       const string& event)> predicate) {
  
  vector<pair<Date, string>> v;
  for (const auto& date_events : DATABASE) {
    Date date = date_events.first;
    for (const auto& event : date_events.second) {
      if (predicate(date, event) == true) {
         //tmp.first = date;
         //tmp.second = event;
         v.push_back({date, event});
      }
    }
  }
  return v;
}


//template<typename PredicateType>
int Database::RemoveIf(function<bool(const Date& date, 
			             const string& event)> predicate) {
  int counter = 0;
  unsigned old_size, new_size;
  vector<Date> empty_dates;
  for (auto date_events = DATABASE.begin(); date_events != DATABASE.end(); date_events++) {
    
    Date date = date_events -> first;
    vector<string> & events = date_events -> second;
    old_size = events.size();
    
    auto unary_predicate = [date, predicate](const string& event) {
      return predicate(date, event);
    };
    auto it = remove_if(events.begin(), events.end(), unary_predicate);
    events.erase(it, events.end());
    new_size = events.size();

    counter += old_size - new_size;
    if (new_size == 0) {
      empty_dates.push_back(date);
    } 
  }

  for (const auto& date : empty_dates) {
    DATABASE.erase(date);
  }

  return counter;
}


pair<Date, string>
Database::Last(const Date& date) {
  if (DATABASE.size() == 0 
	|| date < DATABASE.begin() -> first) {
    throw invalid_argument("");
  }

  /// date >= min_date --> upper_bound > begin(DATABASE)
  auto needed_date = prev(DATABASE.upper_bound(date));
  unsigned events_in_date = needed_date -> second.size();
  return {needed_date -> first, 
	  needed_date -> second[events_in_date - 1]};
}


///______________________________________________________________________________________________________________

void Database::Find(const Date& date) const {
  if (DATABASE.count(date) > 0) {
    for (const auto& event : DATABASE.at(date)) {
      cout << event << endl;
    }
  }
}

void Database::Print(ostream & os) const {
  for (const auto& item : DATABASE) {
    for (const auto& event : item.second) {
      os << item.first << " " << event << endl;
    }
  }
}
