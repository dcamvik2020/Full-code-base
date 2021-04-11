#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <limits>
#include <tuple>
#include <cstdint>

using namespace std;

/// Queries --->
/// time doesn't decrease from one query to another

struct Query {
  string hotel;
  uint64_t client;
  uint64_t rooms;
  int64_t time;

  Query(string a, uint64_t b = 0, uint64_t c = 0, 
        int64_t d = std::numeric_limits<int64_t>::min())
	: hotel(a), client(b), rooms(c), time(d) {}
};

class Database {
private:
  int64_t current_time; /// last BOOK command
  static const int64_t MIN_TIME = std::numeric_limits<int64_t>::min();
  
  /// keep different info for last 24 hours
  deque<Query> queries;
  map<string, uint64_t> booked_rooms_in_hotels;
  map<string, set<uint64_t>> clients_in_hotels;

  
  void Clean() {
    bool changed = false;
    string hotel;
    uint64_t rooms;
    uint64_t client;
    while(queries.size() > 0 &&
          queries[0].time <= current_time - 86400) {
      tie(client, hotel, rooms) = make_tuple(
          queries[0].client, queries[0].hotel, queries[0].rooms
      );
      booked_rooms_in_hotels[hotel] -= rooms;
      clients_in_hotels[hotel].erase(client);
      queries.pop_front();
      changed = true;
    }
    if (changed) {  /// idea : the business is very fast --> we "rare" delete
      for (const auto & query : queries) {   /// old queries ---> this cycle will
        clients_in_hotels[query.hotel].insert(query.client); /// be ..
      }                 /// amotized
    }
  }
   
public:
  Database() : current_time(0) {}

  void Book (int64_t time, const string & hotel,
	       uint64_t client_id, uint64_t rooms) {
    current_time = time;
    /// time doesn't decreass ---> push_back
    queries.push_back(Query{hotel, client_id, rooms, time});
    booked_rooms_in_hotels[hotel] += rooms;
    clients_in_hotels[hotel].insert(client_id);
  }

  // count different clients for hotel (last 24 hours)
  uint64_t Clients(const string & hotel_name) {
    Clean();
    /*
    set<int> s;
    for (const auto & query : queries) {
      if (query.hotel == hotel_name) {
        s.insert(query.client);
      }
    }
    return s.size();*/
    return clients_in_hotels[hotel_name].size();
  }

  // count rooms booked in last 24 hours
  uint64_t Rooms(const string & hotel_name) {
    Clean();
    return booked_rooms_in_hotels[hotel_name];
  }
};

int main() {
  /// some optimizations
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Database db;

  size_t query_count;
  cin >> query_count;

  for (size_t query_id = 0; query_id < query_count; ++query_id) {
    string cmd;
    cin >> cmd;

    if (cmd == "BOOK") {
      int64_t time;
      string hotel(12, '\0');
      uint64_t client_id;
      uint64_t room_count;
      cin >> time >> hotel >> client_id >> room_count;
      db.Book(time, hotel, client_id, room_count);
    } else if (cmd == "CLIENTS") {
      string hotel(12, '\0');
      cin >> hotel;
      cout << db.Clients(hotel) << '\n';
    } else if (cmd == "ROOMS") {
      string hotel(12, '\0');
      cin >> hotel;
      cout << db.Rooms(hotel) << '\n';
    }
  }
}
