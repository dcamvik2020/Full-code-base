#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse {
  // Наполните полями эту структуру
  string stop;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string bus;
  vector<vector<string >> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, vector<string >> m;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
