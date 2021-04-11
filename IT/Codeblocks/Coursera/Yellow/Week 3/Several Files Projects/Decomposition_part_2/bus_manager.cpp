
#include "bus_manager.h"


void BusManager::AddBus(const string & bus, const vector < string > & stops) {
  /// Реализуйте этот метод
    
  buses_to_stops[bus] = stops;
  for (const string & stop : stops) {
    stops_to_buses[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
  /// Реализуйте этот метод
  BusesForStopResponse result;
  result.stop = stop;
  if (stops_to_buses.count(stop) > 0) {
    result.buses = stops_to_buses.at(stop);
  }
  return result;
}
 
StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
  // Реализуйте этот метод
  StopsForBusResponse result;
  result.bus = bus;

  if (buses_to_stops.count(bus) == 0) {
    return result;
  } 

  for (const string & stop : buses_to_stops.at(bus)) {
    vector<string> stop_description;
    stop_description.push_back(stop);

    if (stops_to_buses.at(stop).size() == 1) {
      stop_description.push_back("no interchange");
    } else {
      for (const string & other_bus : stops_to_buses.at(stop)) {
        if (bus != other_bus) {
          stop_description.push_back(other_bus);
        }
      }
    }

    result.stops.push_back(stop_description);
  }
  
  return result;
}

AllBusesResponse BusManager::GetAllBuses() const {
  // Реализуйте этот метод
  AllBusesResponse result;
  result.m = buses_to_stops;
  return result;
}
 
