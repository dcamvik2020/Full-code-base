#include <iostream>
#include <exception>
#include <string>
using namespace std;

/// We have a function: string AskTimeServer()
/// She works with a time server, asks it about
/// current time
/// Success --> func returns time as a string
/// Problem --> func throws an exception
///                  system_error;
/// It can throw other exceptions to tell about
/// different errors or problems.


/// Task: to make a class

/// GetCurrentTime calls AskTimeServer, write the
/// result to last_fetched_time ---> the user doesn't
/// see network problems

/// Other exceptions ---> throw it further
/// because we can't solve in our class other
/// problems


string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
    throw exception();
    throw system_error(error_code());
    return "01:02:34";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        } catch (system_error& se) {
            return last_fetched_time;
        }

        /// all other exceptions will be thrown to
        /// the nearest "catch" block that eccepts it
        /// so, it will be thrown to main()

        ///catch (exception& ex) {
        ///    throw ex;
        ///}
    }
private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
