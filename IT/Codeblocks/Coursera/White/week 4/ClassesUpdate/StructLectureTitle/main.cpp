#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string new_value) {
        value = new_value;
    }
};
struct Course {
    string value;
    explicit Course(string new_value) {
        value = new_value;
    }
};
struct Week{
    string value;
    explicit Week(string new_value) {
        value = new_value;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& new_specialization,
                 const Course& new_course,
                 const Week& new_week) {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
};


/// SOLUTION : we need to define 3 structures in such a way, that we couldn't
/// use any wrong order in parameteres in LectureTitle
/// and parameteres without needed constructors from those 3 structures
/// ---> we need use   EXPLICIT CONSTRUCTORS
int main()
{
    /// we need to create     constructor, destructor     for LectureTitle
    /// and define 3 extra structures in such a way:
    /// this code is availabel
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    /// these commands are not availabel:
    //LectureTitle title("C++", "White belt", "4th");
    //LectureTitle title(string("C++"), string("White belt"), string("4th"));
    //LectureTitle title = {"C++", "White belt", "4th"};
    //LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
    //LectureTitle title(
    //    Course("White belt"),
    //    Specialization("C++"),
    //    Week("4th")
    //);
    //LectureTitle title(
    //    Specialization("C++"),
    //    Week("4th"),
    //    Course("White belt")
    //);
    /// END

    cout << "Hello world!" << endl;
    return 0;
}
