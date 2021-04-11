#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    int day;        /// date
    int month;      /// of
    int year;       /// birth
};


int main()
{
    int N;
    cin >> N;
    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i].name >> students[i].surname >>
               students[i].day >> students[i].month >> students[i].year;
    }

    int M, student;
    cin >> M;
    string request;
    for (; M; --M) {
        cin >> request >> student;
        if ((request != "name" && request != "date") || (student < 1) || (student > N)) {
            cout << "bad request" << endl;
        } else if (request == "name") {
            cout << students[student - 1].name << " " << students[student - 1].surname << endl;
        } else {
            cout << students[student - 1].day << "." << students[student - 1].month << "." << students[student - 1].year << endl;
        }
    }
    return 0;
}
