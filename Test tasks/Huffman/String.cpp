#include "String.h"

void Reverse(std::string& tmp) {
    for (unsigned i = 0; i < tmp.size() / 2; ++i) {
        std::swap(tmp[i], tmp[tmp.size() - i - 1]);
    }
}


/// now I don't need these 2 functions, they are in <cstring>

int my_strcmp(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() - s2.size();
    }
    for (unsigned i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int my_strncmp(const std::string& s1, const std::string& s2 , unsigned len) {
    if (s1.size() < len || s2.size() < len) {
        return s1.size() - s2.size();
    } else {
        for (unsigned i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                return s1[i] - s2[i];
            }
        }
    }
    return 0;
}



bool is_null(const std::string& s) {
    /// if s is empty --> forgive it ^^
    /// we check only not empty strings
    if (s.size() == 0) {
        return false; /// s is not "00...00"
    }

    /// s consists of 0\1
    for (unsigned i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            return false;
        }
    }
    return true;
}
