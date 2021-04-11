#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void NEW_BUS (map<string, vector<string>>& bus_stops, vector<string>& order) {
    /// really new bus --> it doesn't exist
    /// stop_count > 0
    int stop_count;
    string new_bus, stop;
    cin >> new_bus >> stop_count;
    vector<string> stops;
    for (int i = 0; i < stop_count; ++i) {
        cin >> stop;
        stops.push_back(stop);
    }
    bus_stops[new_bus] = stops;
    order.push_back(new_bus);
}

void BUSES_FOR_STOP(map<string, vector<string>>& bus_stops, const vector<string>& order, const string& stop) {
    bool flag = false;
    for (int i = 0; i < order.size(); ++i) {
        string bus = order[i];
        vector<string> stops = bus_stops[bus];
        if (count(begin(stops), end(stops), stop) > 0) {
            if (flag == false) {
                //cout << "Stop " << stop << ": ";
                flag = true;
            }
            cout << bus << " ";
        }
    }
    if (flag == false) {
        cout << "No stop";
    }
}

void STOPS_FOR_BUS(map<string, vector<string>>& bus_stops, vector<string>& order, const string& bus) {

    if (bus_stops.count(bus) == 0) {
        cout << "No bus" << endl;
        return;
    }

    for (auto& stop : bus_stops[bus]) {
        bool flag = false;
        cout << "Stop " << stop << ": ";
        for (int i = 0; i < order.size(); ++i) {
            string tmp_bus = order[i];
            if ((tmp_bus != bus)) {
                vector<string> tmp_stops = bus_stops[tmp_bus];
                if (count(begin(tmp_stops), end(tmp_stops), stop) > 0) {
                    flag = true;
                    cout << tmp_bus << " ";
                }
            }
        }
        if (flag == false) {
            cout << "no interchange";
        }
        cout << endl;
    }
}


int main()
{
    int Q;
    cin >> Q;
    string request;

    /// for each bus --> vector(string)
    vector<string> order;
    map<string, vector<string>> bus_stops;

    for (; Q; --Q) {
        cin >> request;
        if (request == "NEW_BUS") {
            NEW_BUS(bus_stops, order);
        } else if (request == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            BUSES_FOR_STOP(bus_stops, order, stop);
            cout << endl;
        } else if (request == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            STOPS_FOR_BUS(bus_stops, order, bus);
            //cout << endl;
        } else if (request == "ALL_BUSES") {
            if (bus_stops.empty()) {
                cout << "No buses" << endl;
                continue;
            }
            for (auto bus : bus_stops) {
                cout << "Bus " << bus.first << ": ";
                for (int j = 0; j < bus.second.size(); ++j) {
                    cout << bus.second[j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
