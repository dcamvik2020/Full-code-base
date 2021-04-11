#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
private:
  vector<vector<T>> table;
public:
  Table(size_t height, size_t width) {
    table.resize(height);
    for (auto & line : table) {
      line.resize(width);
    }
  }


  const vector<T> & operator [] (size_t index) const {
    return table[index]; /// TASK : we don't need to check validness
  }
  vector<T> & operator [] (size_t index) {
    return table[index];
  }

  void Resize(size_t new_h, size_t new_w) {
    table.resize(new_h);
    for (auto & line : table) {
      line.resize(new_w); 
    }
  }

  pair<size_t, size_t> Size() const {
    return {table.size(), table.empty() ? 0 : table[0].size()};
  }
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
  ASSERT_EQUAL(t[1][1], 0);


  Table<float> f(3, 3);
  for (size_t i = 0; i < f.Size().first; ++i) {
    for (size_t j = 0; j < f.Size().second; ++j) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }cout << endl;

  Table<string> s(3, 3);
  for (size_t i = 0; i < s.Size().first; ++i) {
    for (size_t j = 0; j < s.Size().second; ++j) {
      ASSERT_EQUAL(s[i][j], "");
    }
    cout << endl;
  }cout << endl;

  Table<double> d(3, 3);
  for (size_t i = 0; i < d.Size().first; ++i) {
    for (size_t j = 0; j < d.Size().second; ++j) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }cout << endl;

}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
