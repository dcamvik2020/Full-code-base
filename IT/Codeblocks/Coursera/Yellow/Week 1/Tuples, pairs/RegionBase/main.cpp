#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

bool operator < (const Region& a, const Region& b) {
    /// we have references --> use not make_tuple(), but tie()
    /// we can  write    tuple1 < tuple2 --> use it
    return tie(a.std_name, a.parent_std_name,
               a.names, a.population)

           <

           tie(b.std_name, b.parent_std_name,
               b.names, b.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    /// if all are unique ---> return 1;
    int Max_count = 1;
    map<Region, int> regions_count;
    for (const auto& one_region : regions) {
        Max_count = max(Max_count, ++regions_count[one_region]);
    }
    return Max_count;
}

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

/// non-effective
/*
int CountRegionInRegions(const vector<Region>& regions, const Region& one_region) {
    return count_if(regions.begin(), regions.end(), [&one_region](const Region& x) {
            /// [&one_region] ---> we need to capture local variables
            /// to be able to use them in lambda-functions
            if (x.std_name != one_region.std_name) {
                return false;
            }
            if (x.parent_std_name != one_region.parent_std_name) {
                return false;
            }
            if (x.population != one_region.population) {
                return false;
            }
            if (x.names.size() != one_region.names.size()) {
                return false;
            }
            if (x.names.at(Lang::DE) != one_region.names.at(Lang::DE)) {
                return false;
            }
            if (x.names.at(Lang::FR) != one_region.names.at(Lang::FR)) {
                return false;
            }
            if (x.names.at(Lang::IT) != one_region.names.at(Lang::IT)) {
                return false;
            }
            return true;
        }
    );
}


int FindMaxRepetitionCount(const vector<Region>& regions) {
    /// if all are unique ---> return 1;
    int Max_count = 0, count_one_region;
    for (const auto& one_region : regions) {
        count_one_region = CountRegionInRegions(regions, one_region);
        if (Max_count < count_one_region) {
            Max_count = count_one_region;
        }
    }
    return Max_count;
}
*/

/// we want to count     QUANTITY for every REGION
/// logical : to create    map<Region, int>
/// for map we need  operator <
/// then we will be able to compare elements of vector<Region>
/// also it will be done by only one array pass

bool operator < (const Region& a, const Region& b) {
    /// we have references --> use not make_tuple(), but tie()
    /// we can  write    tuple1 < tuple2 --> use it
    return tie(a.std_name, a.parent_std_name,
               a.names, a.population)

           <

           tie(b.std_name, b.parent_std_name,
               b.names, b.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    /// if all are unique ---> return 1;
    int Max_count = 0;
    map<Region, int> regions_count;
    for (const auto& one_region : regions) {
        Max_count = max(Max_count, ++regions_count[one_region]);
    }
    return Max_count;
}


int main() {
    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
    }) << endl;

    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
    }) << endl;

  return 0;
}
