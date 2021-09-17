#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    int WayNum = 1;
    map<int, vector<string>> BusWays;

    for (; Q; --Q) {
        ///_________put int the way_____________________
        int CountStops;
        cin >> CountStops;
        vector<string> NewWay(CountStops);
        for (auto& stop : NewWay) {
            cin >> stop;
        }

        ///_________check existance of the way__________
        bool equals = false;
        for (auto& way : BusWays) {
            /// check every busway
            if (NewWay == way.second) {
                cout << "Already exists for " << way.first << endl;
                equals = true;
                break;
            }
        }

        ///__________add new way________________________
        if (equals == false) {
            BusWays[WayNum] = NewWay;
            cout << "New bus " << WayNum << endl;
            ++WayNum;
        }
    }

    return 0;
}
