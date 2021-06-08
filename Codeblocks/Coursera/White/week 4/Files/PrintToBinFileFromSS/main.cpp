#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void PrintToBinFileFromSS(ofstream& output, stringstream& SS) {
    char c; /// only '0' and '1'
    char tmp = 0;
    char cnt; /// counter of bits 0/1
    for (cnt = 0; 1; ++cnt) {
        SS >> c;
        if (SS.fail() == false) {
            //cout << "Char : " << c << endl;
            if (cnt < 8) {
                /// 2*63+1 = 127 (max char)
                tmp = 2 * tmp + (c - '0');
            } else {
                cout << tmp;
                output << tmp;
                tmp = 0;
                cnt = 0;
            }
        } else {
            break;
        }
    }
    cout << tmp;
    output << tmp;
}

void Reverse(string& s) {
    for (unsigned i = 0; i < s.size() / 2; ++i) {
        swap(s[i], s[s.size() - i - 1]);
    }
}

int my_strncmp(const string& s1, const string& s2 ,unsigned len) {
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

void PrintFromBinFileToSS(ifstream& input, stringstream& SS, vector<string> codes) {
    char c; /// c --> string of '0', '1'
    string buf = ""; /// buffer for not used parts
    while (1) {
        input >> c;
        if (input.fail() == false) {
            string s = buf;
            /// get string of '0', '1' from "c" -- code
            while (c) {
                s += '0' + c % 2;
                c /= 2;
            }
            Reverse(s);

            /// now, find code or save it in buf
            bool read_all = false;
            while (s.size() && read_all == false) {
                unsigned how_many_read = 0;
                for (unsigned i = 0; i < codes.size(); ++i, ++how_many_read) {
                    //cout << "     codes[i] : " << codes[i]
                    //     << "     s.size() = " << s.size()
                    //     << "      s = " << s;
                    int res = my_strncmp(s, codes[i], codes[i].size());
                    if (res == 0) {
                        /// they equal -->
                        SS << (char)('a' + i);
                        for (unsigned j = codes[i].size(); j < s.size(); j++) {
                            s[j - codes.size()] = s[j];
                        }
                        s.resize(s.size() - codes[i].size());
                        if (buf.size() >= codes[i].size()) {
                            buf.resize(buf.size() - codes[i].size());
                        }
                        /*for (unsigned j = codes[i].size(); j < buf.size(); j++) {
                            buf[j - codes.size()] = buf[j];
                        }
                        buf[buf.size() - codes[i].size()] = 0;
                        */
                        //cout << "     buf = " << buf << endl;
                        break;
                    }
                    //cout << endl;
                }
                if (how_many_read == codes.size()) {
                    read_all = true;
                }

            }
                /// the rest we ssave in buf
                buf += s;
        } else {
            break;
        }
    }
    //cout << SS.str() << endl;
}

int main()
{
 //   string line;
 //   cin >> line; /// 0 and 1
    vector<string> codes;
    codes.push_back("10");
    codes.push_back("11");
/*    ofstream output;
    output.open("output.txt", ios::binary | ios::out);
    stringstream SS(line);
    PrintToBinFileFromSS(output, SS);
    output.close();
*/
    ifstream input;
    input.open("output.txt", ios::binary | ios::in);

    stringstream SS1;
    PrintFromBinFileToSS(input, SS1, codes);
    cout << "str = " << SS1.str() << endl;
    return 0;
}
