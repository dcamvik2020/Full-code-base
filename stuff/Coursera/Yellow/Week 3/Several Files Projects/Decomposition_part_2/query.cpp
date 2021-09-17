
#include "query.h"

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию

  // clear query
  q.bus = "";
  q.stop = "";
  q.stops.clear();

  /// input
  string cmd;
  is >> cmd;
  if (cmd == "NEW_BUS") {
    string stop;
    unsigned stops_count;
    q.type = QueryType::NewBus;
    is >> q.bus;
    is >> stops_count;
    for (unsigned i = 0; i < stops_count; ++i) {
      is >> stop;
      q.stops.push_back(stop);
    }
  } else if (cmd == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (cmd == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (cmd == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

