// Overload -- usual overload as in physics
//           non-gravitive acceleration / g (9,8 N)

// Distance > 0 : from the Earth
// Distance < 0 : to the Earth

// 3 methods of calculating ---> code it

// start speed = 0

#include <iostream>
#include <time.h>

using namespace std;

#define g 9.8

double overload(double s, double t) {
    double a = 2 * s / t / t;
    /// a-> = a_extern-> + g-> (vectors)
    /// a = a_extern - g (scalar equation)
    return (a + g) / g;
}

double overload(double s, struct tm t) { /// struct from <time.h>
    /// from struct tm --> use tm_sec, tm_min, tm_hour
    double time = t.tm_sec + t.tm_min * 60 + t.tm_hour * 3600;
    return overload(s, time);
}

double overload(double s, const char *t) { /// hh:mm:ss
    struct tm time;
    sscanf(t, "%d:%d:%d", &time.tm_hour, &time.tm_min, &time.tm_sec);
    //strptime(t, "%H:%M:%S", &time); /// searching for this function wasn't a nice process
    return overload(s, time);
}

int main()
{
    cout << overload(490, 10) << endl;
    cout << overload(-490, 10) << endl << endl << endl;

    struct tm t;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 10;
    cout << overload(490, t) << endl;
    cout << overload(-490, t) << endl << endl << endl;

    cout << overload(490, "00:00:10") << endl;
    cout << overload(-490, "00:00:10") << endl;
    cout << overload(-216090, "00:03:30") << endl;
    return 0;
}

