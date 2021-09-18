#include <iostream>
#include <exception>
#include <map>

using namespace std;

template <typename Key, typename Value>
const Value & GetRefStrict (const map<Key, Value> & m, const Key & key);

template <typename Key, typename Value>
Value & GetRefStrict (map<Key, Value> & m, const Key & key);


template <typename Key, typename Value>
const Value & GetRefStrict (const map<Key, Value> & m, const Key & key) {
    if (m.count(key) == 0) {
        throw runtime_error("");
    }
    return m[key];
}

template <typename Key, typename Value>
Value & GetRefStrict (map<Key, Value> & m, const Key & key) {
    if (m.count(key) == 0) {
        throw runtime_error("");
    }
    return m[key];
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; ///newvalue
    return 0;
}
