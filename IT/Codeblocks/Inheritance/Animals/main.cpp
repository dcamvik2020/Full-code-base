#include <iostream>

class Animal {
protected:
  std::string name;
  std::string type;
  Animal(const std::string & name_0, const std::string & type_0)
	  : name(name_0), type(type_0) {}
public:
  virtual ~Animal() {}
  const char * GetName() const {return name.c_str();}
  const char * GetType() const {return type.c_str();}
  virtual const char * Sound() const  = 0;
};

const char * Animal::Sound() const {
  return "???";
}

class Cat : public Animal {
private:
public:
  Cat(const std::string & name) : Animal(name, "Cat") {}
  const char * Sound() const override {return "Meow";}
};

class Dog : public Animal {
private:
public:
  Dog(const std::string & name) : Animal(name, "Dog") {}
  const char * Sound() const override {return "Bark";}
};

int main() {
  return 0;
}
