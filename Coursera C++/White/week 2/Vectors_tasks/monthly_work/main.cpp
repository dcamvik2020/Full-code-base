#include <iostream>
#include <vector>
#include <map>

using namespace std;

int month = 0;
const vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void ADD(vector<vector<string>>& work, const int& day, const string& activity) {
    if (day <= days_in_months[month]) {
        work[day - 1].push_back(activity);
    }
}

void DUMP(vector<vector<string>>& work, int day) {
    if (day <= days_in_months[month]) {
        cout << work[day - 1].size() << " ";
        for (int i = 0; i < work[day - 1].size(); ++i) {
            cout << work[day - 1][i] << " ";
        }
        cout << endl;
    }
}

void NEXT(vector<vector<string>>& work) {
    if (month < 11) {
        int cur_days, next_days;
        cur_days = days_in_months[month];
        next_days = days_in_months[month + 1];
        if (next_days < cur_days) {
            for (int extra_days = next_days; extra_days < cur_days; ++extra_days) {
                work[next_days - 1].insert(end(work[next_days - 1]),
                                           begin(work[extra_days]),
                                           end(work[extra_days]));

            }
        }

        work.resize(days_in_months[month + 1]);
        ++month;
    } else { /// mew year -- new life!
        for (auto v : work) {
            v.clear();
        }
        work.resize(31);
        month = 0;
    }

}

int main()
{
    int Q, day;
    string cmd, activity;
    vector<vector<string>> work(days_in_months[month]);
    //cout << work.size() << endl;
    cin >> Q;
    for (; Q; --Q) {
        cin >> cmd;
        if (cmd == "ADD") {
            cin >> day >> activity;
            ADD(work, day, activity);
        } else if (cmd == "DUMP") {
            cin >> day;
            DUMP(work, day);
        } else if (cmd == "NEXT") {
            NEXT(work);
        } else {
            ++Q;
        }
    }

    return 0;
}
