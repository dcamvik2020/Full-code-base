#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> m;
	string s;

	cout << "Ivanov's name: "; cin >> s;
	m["Ivanov"] = s;
	cout << "Petrov's name: "; cin >> s;
	m["Petrov"] = s;
	cout << "Sidorov's name: "; cin >> s;
	m["Sidorov"] = s;

	cout << "Ivanov " << m["Ivanov"] << endl;
	cout << "Petrov " << m["Petrov"] << endl;
	cout << "Sidorov " << m["Sidorov"] << endl;
	return 0;
}
