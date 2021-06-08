#include <iostream>

class Human {
private:
  std::string name;
  int age;
  int height;
  int weight;
  std::string hair;
  std::string eyes;
public:
  Human(const std::string & name_0 = "", int age_0 = 0)
	  name(name_0), age(age_0) {}
  ~Human() {}
  const string & GetName() const {return name;}
  int GetAge() const {return age;}

};

class Mother : public Human{
private:
  ;
public:
  ;
};
class Father :public Human {
private:
  ;
public:
  ;
};

class Child : public Mother, public Father {};




