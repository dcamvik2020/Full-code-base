#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>

#include <set>
#include <algorithm>
using namespace std;

class ReadingManager {
private:
  size_t count_users;
  static const int MAX_USER_COUNT_ = 100'000;
  static const int MAX_PAGE_COUNT_ = 1000;
  vector<size_t> user_page_counts_;
  vector<set<size_t>> pages_to_users_; /// for every page list of users

public:
  ReadingManager() : count_users(0)
	           , user_page_counts_(MAX_USER_COUNT_ + 1, 0)
		   , pages_to_users_(MAX_PAGE_COUNT_ + 1) {}
  
  void Read(size_t user_id, size_t page_count) {
    if (user_page_counts_[user_id] == 0) {
      count_users++;
    }
    pages_to_users_[user_page_counts_[user_id]].erase(user_id);
    user_page_counts_[user_id] = page_count;
    pages_to_users_[page_count].insert(user_id);  
  }

  double Cheer(size_t user_id) const {
    if (user_page_counts_[user_id] == 0) {
      return 0;
    }
    if (count_users == 1) {
      return 1;
    }

    size_t read_less_user_id = 0;
    size_t user_page = user_page_counts_[user_id];

    for (size_t page = 1; page < user_page; ++page) {
      read_less_user_id += pages_to_users_[page].size();
    }
    return (double) read_less_user_id / (count_users - 1);
  }
};



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  size_t query_count;
  cin >> query_count;

  for (size_t query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    size_t user_id;
    cin >> user_id;

    if (query_type == "READ") {
      size_t page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }
  return 0;
}
