#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public:
  Figure() {}
  virtual string Name () const = 0;
  virtual double Area () const = 0;
  virtual double Perimeter () const = 0;
};

class Rect : public Figure {
private:
  double width;
  double height;
public:
  Rect(int w, int h) : width(w), height(h) {}
  virtual string Name () const {return "RECT";};
  virtual double Area () const {return width * height;};
  virtual double Perimeter () const {return 2 * (width + height);};

};

class Triangle : public Figure {
private:
  double a, b, c;
public:
  Triangle(int s1, int s2, int s3) : a(s1), b(s2), c(s3) {}
  virtual string Name () const override {return "TRIANGLE";};
  virtual double Area () const override{
    double p = (a + b + c) / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
  };
  virtual double Perimeter () const override {return a + b + c;};

};

class Circle : public Figure {
private:
  double radius;
public:
  Circle(int r) : radius(r) {}
  virtual string Name () const override {return "CIRCLE";};
  virtual double Area () const override {return 3.14 * radius * radius;};
  virtual double Perimeter () const override {return 3.14 * 2 * radius;};
};

shared_ptr<Figure>
CreateFigure(istream & is) {
  string type_of_figure;
  is >> type_of_figure;

  if (type_of_figure == "RECT") {
    int width, height;
    is >> width >> height;
    return make_shared<Rect>(width, height);
  } else if (type_of_figure == "TRIANGLE") {
    int a, b, c;
    is >> a >> b >> c;
    return make_shared<Triangle>(a, b, c);
  } else if (type_of_figure == "CIRCLE") {
    int r;
    is >> r;
    return make_shared<Circle>(r);
  }

  
  /// we never get here
  /// also we may throw an exception here... ))
  return make_shared<Circle>(0);
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
