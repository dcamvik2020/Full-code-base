#include <iostream>
#include <vector>

using namespace std;

int pos(const string & line, int size);
void Correct(string & s) {
  int new_size = s.size(); 
  while (new_size && ((s[new_size-1] == ' ') || 
             ( s[new_size-1] == '\t') || (s[new_size-1] == '\n')
         )) {new_size--;}
  s.resize(new_size);
}

int main() {
  string obj, text;
  getline(cin, obj);
  getline(cin, text);
  Correct(obj), Correct(text);
  int res = pos(obj + "#" + text, obj.size());
  cout << res << ", " << text[res] << endl;
  return 0;
}

int pos(const string & line, int size) {
  vector<int> pref_func(line.size(), 0);
  for (int i = 1; i < pref_func.size(); ++i) {
    int k = pref_func[i-1];
    if (line[k] == line[i]) {
      pref_func[i] = pref_func[i-1] + 1;
    } else {
      while (k > 0 && line[k] != line[i]) {
        k = pref_func[k];
      }
      if (k == 0) pref_func[i] = (line[0] == line[i]);
      else pref_func[i] = pref_func[k];
    }
		
    if (pref_func[i] == size) return i - 2 * size;
  }
  //cout << "size = " << size << endl;
  //for (int i = 0; i < pref_func.size(); ++i) {
  //	if (i == size) cout << "#" << " ";
  //	else cout << line[i] << " ";
  //}
  //cout << endl;
  //for (int i = 0; i < pref_func.size(); ++i) {
  //	cout << pref_func[i] << " ";
  //}
  //cout << endl;
  return -1;
}
