#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void CHANGE_CAPITAL (map<string, string>& Rus_Msk, const string& country, const string& new_capital) {
    if (!Rus_Msk.count(country)) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    } else if (Rus_Msk[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << Rus_Msk[country] << " to " << new_capital << endl;
    }
    Rus_Msk[country] = new_capital;
}

void RENAME (map<string, string>& Rus_Msk, const string& old_country_name, const string& new_country_name) {
    bool old_exists = Rus_Msk.count(old_country_name);
    bool new_exists = Rus_Msk.count(new_country_name);
    bool cmp = (old_country_name == new_country_name);

    if (old_exists == false || new_exists == true || cmp == true) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << old_country_name << " with capital " << Rus_Msk[old_country_name] << " has been renamed" <<
                                                                           " to " << new_country_name << endl;
        auto it = Rus_Msk.find(old_country_name);
        Rus_Msk[new_country_name] = it->second;
        Rus_Msk.erase(old_country_name);
    }
}

void ABOUT (const map<string, string>& Rus_Msk, const string& country) {
    if (Rus_Msk.count(country) > 0) {
        cout << "Country " << country << " has capital " << Rus_Msk.at(country) << endl;
    } else {
        cout << "Country " << country << " doesn't exist" << endl;
    }
}

void DUMP (const map<string, string>& Rus_Msk) {
    if (Rus_Msk.size() == 0) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (auto country : Rus_Msk) {
            cout << country.first << "/" << country.second << " ";
        }
        cout << endl;
    }
}

int main()
{
    int Q;
    cin >> Q;

    string request;
    string country;
    string new_country_name;
    string city;

    map<string, string> Rus_Msk; /// country-capital

    for (; Q; --Q) {
        cin >> request;

        if (request == "DUMP") {
            DUMP(Rus_Msk);
        } else {
            cin >> country; /// without spaces
            ///              !! RussianFederation !!

            if (request == "CHANGE_CAPITAL")
            {
                cin >> city;
                CHANGE_CAPITAL(Rus_Msk, country, city);
            }
            else if (request == "RENAME")
            {
                cin >> new_country_name;
                RENAME(Rus_Msk, country, new_country_name);
            }
            else if (request == "ABOUT")
            {
                ABOUT(Rus_Msk, country);
            }
        }

    }

    return 0;
}
