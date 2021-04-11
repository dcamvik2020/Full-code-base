#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out("out.txt");
    out << "Hello world! 1 " << endl;
    out.seekp(0);
    out << "Hello world! 2 " << endl;
    /// in the end it is "...2"


    ifstream in;//("in.txt");

    in.open("in.txt", ios::in);

    string line;
    cout << "1" << endl;
    while (getline(in, line)) cout << line << endl;

    in.close();
    in.open("in.txt", ios::in);
    in.seekg(0);
    cout << "2" << endl;
    while (getline(in, line)) cout << line << endl;


    return 0;
}
