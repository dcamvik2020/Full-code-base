#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  string Name;
  string Profession;

  Person (string name, string prof) : Name(name), Profession(prof) {
  }
  virtual void Walk (string destination) const {
    cout << Profession + ": " + Name + " walks to: " + destination << endl;
  }
};

class Student : public Person {
public:
  string FavouriteSong;
public:

  Student (string name, string favouriteSong)
      : Person(name, "Student")
      , FavouriteSong(favouriteSong) {}

  void Learn () const {
    cout << "Student: " << Name << " learns" << endl;
  }

  void Walk (string destination) const override {
    cout << "Student: " << Name << " walks to: " << destination << endl;
    cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
  }

  void SingSong () const {
    cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
  }
};


class Teacher : public Person {
public:
  string Subject;
public:
  Teacher (string name, string subject) 
        : Person(name, "Teacher")
        , Subject(subject) {}

  void Teach () const {
    cout << "Teacher: " << Name << " teaches: " << Subject << endl;
  }
};


class Policeman : public Person{
public:
  Policeman (string name)
        : Person(name, "Policeman") {}

  void Check (Person person) const {
    cout << "Policeman: " << Name << " checks " << person.Profession << ". " << person.Profession << "'s name is: " << person.Name << endl;  
  }
};

void VisitPlaces(const Person & person, vector < string > places) {
  for (auto p : places) {
    person.Walk(p);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {
    "Moscow", "London"
  }
  );
  p.Check(s);
  VisitPlaces(s, {
    "Moscow", "London"
  }
  );
  return 0;
}
