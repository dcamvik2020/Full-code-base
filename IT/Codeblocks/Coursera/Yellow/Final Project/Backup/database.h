#pragma once

#include <iostream>
#include <iomanip>

#include <exception>
#include <functional>
#include <algorithm>

#include <vector>
#include <map>
#include <set>
#include <utility>

#include "date.h"

using namespace std;

class Database {
private:
    map<Date, vector<string>> DATABASE;
public:
    void Add(const Date& date, const string& event);

    //template<class PredicateType>
    vector<pair<Date, string>> 
    FindIf(function<bool(const Date& date, const string& event)> predicate);
    
    //template<typename PredicateType>
    int RemoveIf(function<bool(const Date& date, const string& event)> predicate);

    pair<Date, string>
    Last(const Date& date);    


    /*set<string>*/
    void Find(const Date& date) const;
    void Print(ostream & os) const;
};

