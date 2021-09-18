#include <iomanip>
#include <string>

using namespace std;

//#include "Date.h"
#include "Database.h"


int main() {
    Database db;
    string command;
    string cmd, date, event;
    while (getline(cin, command)) {
        stringstream stream(command);

        if (stream.str() == "") {
            continue;
        }

        stream >> cmd;
        if (cmd == "Print") {
            db.Print();
        } else if (cmd == "Find") {
            try {
                stream >> date;
                db.Find(Date(date));
            } catch (invalid_argument& invarg) {
                cout << invarg.what() << endl;
                return 1;
            }
        } else if (cmd == "Add") {
            try {
                stream >> date;
                stream >> event;
                db.AddEvent(date, event);
            } catch (invalid_argument& invarg) {
                cout << invarg.what() << endl;
                return 2;
            }
        } else if (cmd == "Del") {
            try {
                stream >> date;
                stream >> event;
                if (stream.fail() == true) {
                    /// didn't read event --> delete the whole date
                    db.DeleteDate(date);
                } else {
                    db.DeleteEvent(date, event);
                }
            } catch (invalid_argument& invarg) {
                cout << invarg.what() << endl;
                return 3;
            }
            stream >> event;
        } else {
            cout << "Unknown command: " << cmd << endl;
        }
    }

    return 0;
}
