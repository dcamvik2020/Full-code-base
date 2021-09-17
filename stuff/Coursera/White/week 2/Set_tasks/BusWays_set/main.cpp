#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    int num_stops;
    string stop;
    vector<set<string>> ways;

    for (; Q; --Q) {
        cin >> num_stops;
        set<string> stops;

        for (int i = 0; i < num_stops; ++i) {
            cin >> stop;
            stops.insert(stop);
        }

        if (count(begin(ways), end(ways), stops) > 0) {
            cout << "Already exists for " << 1 + find(begin(ways), end(ways), stops) - ways.begin()<< endl;
        } else {
            ways.push_back(stops);
            cout << "New bus " << ways.size() << endl;
        }
    }

    return 0;
}
