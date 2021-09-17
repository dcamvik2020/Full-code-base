
#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  if (r.buses.size() == 0) {
    os << "No stop";
  } else {
    bool first = true;
    for (const string & bus : r.buses) {
      if (first == false) {
        os << " ";
      }
      os << bus;
      first = false;
    }
  }
  return os;
}


ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию

  if (r.stops.size() == 0) {
    cout << "No bus";
  } else {
    bool first_str = true;
    for (const auto & stop : r.stops) {
      if (first_str == false) {
        cout << endl;
      }
      cout << "Stop " << stop[0] << ": ";
      bool first_j = true;
      for (unsigned j = 1; j < stop.size(); ++j) {
        if (first_j == false) {
          cout << " ";
        }
        cout << stop[j];
        first_j = false;
      }
      first_str = false;
    }
  }

  return os;
}


ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию

  if (r.m.empty()) {
    os << "No buses";
  } else {
    bool first_i = true;
    for (const auto& bus : r.m) {
      if (first_i == false) {
        os << endl;
      }
      os << "Bus " << bus.first << ": ";
      bool first_j = true;
      for (const string& stop : bus.second) {
        if (first_j == false) {
          os << " ";
        }
        os << stop;
        first_j = false;
      }
      first_i = false;
    }
  }

  return os;
}

