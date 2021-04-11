#include <string>
#include <iostream>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& str) {
        s = str;
    }
    void Reverse() {
        int len = s.size();
        char tmp;
        for (int i = 0; i < len / 2; ++i) {
            tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
    string ToString() const {
        /// receive the string
        return s;
    }
private:
    string s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
