#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <initializer_list>
#include <cmath>

const double pi = 3.1415;

class Figure {
protected:
  double area;
  double perimeter;
  std::string type;
  size_t num_points; /// number of points in figure
public:
  Figure(std::string type_0 = "none", size_t points = 0) 
	  : area(0), perimeter(0), type(type_0), num_points(points) {};
  virtual ~Figure() {} /// inheritance --> destructor better to be virtual
  
  auto GetArea()      const ->        double       {return area;}
  auto GetPerimeter() const ->        double       {return perimeter;}
  auto GetType()      const -> const std::string & {return type;}

  friend std::ostream & operator<< (std::ostream & os, const Figure & fig); 
};

class Square : public Figure {
private:
  double a;

public:
  Square(double a_0) : Figure("Square", 4), a(a_0) {
    perimeter = 4 * a;
    area = a * a;
  }
  Square(const Figure & fig) : Figure("Square", 4) {
    if (fig.GetType() != "none" && fig.GetType() != "Square") {
      throw "Wrong type of figure";
    }
  }
  friend std::ostream & operator<< (std::ostream & os, const Square & fig) {
    return os << "Square: a = " << fig.a << "   S = " << fig.area 
	      << "   P = " << fig.perimeter;
  }
};

class Triangle : public Figure {
private:
  double a, b, c;

public:
  Triangle(double a_0, double b_0, double c_0) 
	  : Figure("Triangle", 3), a(a_0), b(b_0), c(c_0) {
    perimeter = a + b + c;
    area = sqrtf(    perimeter/2      * (perimeter/2 - a) 
		  * (perimeter/2 - b) * (perimeter/2 - c) );
  }
  Triangle(const Figure & fig) : Figure("Triangle", 3) {
    if (fig.GetType() != "none" && fig.GetType() != "Triangle") {
      throw "Wrong type of figure";
    }
  }
  friend std::ostream & operator<< (std::ostream & os, const Triangle & fig) {
    return os << "Triangle: a = " << fig.a 
	      << "   b = " << fig.b << "   c = " << fig.c
	      << "   S = " << fig.area << "   P = " << fig.perimeter;
  }
};

class Rectangle : public Figure {
private:
  double a, b;

public:
  Rectangle(double a_0, double b_0) 
	  : Figure("Rectangle", 4), a(a_0), b(b_0){
    perimeter = 2 * (a + b);
    area = a * b;
  }
  Rectangle(const Figure & fig) : Figure("Rectangle", 4){
    if (fig.GetType() != "none" && fig.GetType() != "Rectangle") {
      throw "Wrong type of figure";
    }
  } 
  friend std::ostream & operator<< (std::ostream & os, const Rectangle & fig) {
    return os << "Rectangle: a = " << fig.a << "   b = " << fig.b 
	      << "   S = " << fig.area << "   P = " << fig.perimeter;
  }
};

class Circle : public Figure {
private:
  double r;

public:
  Circle(double r_0) : Figure("Circle", static_cast<size_t>(-1)), r(r_0) {
    perimeter = 2 * pi * r;
    area = pi * r * r;
  }
  Circle(const Figure & fig) : Figure("Circle", static_cast<size_t>(-1)) {
    if (fig.GetType() != "none" && fig.GetType() != "Circle") {
      throw "Wrong type of figure";
    }
  }
  friend std::ostream & operator<< (std::ostream & os, const Circle & fig) {
    return os << "Circle: r = " << fig.r << "   S = " << fig.area 
	      << "   P = " << fig.perimeter;
  }
};



template <size_t N>
class Points : public Figure {
private:
  static const size_t num_points = N;
  std::vector<std::pair<double, double>> points; /// (x, y)
  void ComputePerimeter() {
    if (N < 2) return;
    bool first = true;
    double dx_squared, dy_squared;
    for (size_t i = 0; i < N; ++i) { 
      if (first == false) {
        dx_squared = (points[i].first - points[i-1].first) *
	             (points[i].first - points[i-1].first);
	dy_squared = (points[i].second - points[i-1].second) *
	             (points[i].second - points[i-1].second);
	perimeter += sqrtf(dx_squared + dy_squared);
      }
      first = false;
    }
    if (N > 2) {
        dx_squared = (points[0].first - points[N-1].first) *
	             (points[0].first - points[N-1].first);
	dy_squared = (points[0].second - points[N-1].second) *
	             (points[0].second - points[N-1].second);
  	perimeter += sqrtf(dx_squared + dy_squared);
    }
  }
public:
  Points() : Figure("Points", N), points(N, {0, 0}) {}
  Points(const std::initializer_list<std::pair<double,double>>& list) 
	  : Figure("Points", N) {
    if (N != list.size()) throw "Wrong size of initializer_list";
    points.resize(N);
    size_t count = 0;
    for (const auto & p : list) {
      points[count++] = p;
    }
    ComputePerimeter();
  }
  Points(const std::vector<std::pair<double, double>> & v) 
	  : Figure("Points", N) {
    if (N != v.size()) throw "Wrong size of vector";
    points.resize(N);
    ComputePerimeter();
  }
  Points(const Figure & fig) : Figure("Points", N)  {
    if (fig.GetType() != "none" && fig.GetType() != "Points") {
      throw "Wrong type of figure";
    }
    ComputePerimeter(); 
  }
  ~Points() {}  
};

template <size_t N>
std::ostream & operator << (std::ostream & os, const Points<N> & fig) {
  return os << "Points<" << N <<  ">"
            << "   S = " << fig.GetArea() 
            << "   P = " << fig.GetPerimeter();
}





std::ostream & operator<< (std::ostream & os, const Figure & fig) {
  if (fig.GetType() == "Square") return os << static_cast<Square>(fig);
  if (fig.GetType() == "Triangle") return os << static_cast<Triangle>(fig);
  if (fig.GetType() == "Rectangle") return os << static_cast<Rectangle>(fig);
  if (fig.GetType() == "Circle") return os << static_cast<Circle>(fig);
  //if (fig.GetType() == "Points") {
  //  const size_t points = fig.num_points;
  //  return os << static_cast<Points<points>>(fig);
  //}
  return os << fig;
}





int main() {
  std::shared_ptr<Figure> fig1(new Circle(4.5));
  std::cout << *(std::dynamic_pointer_cast<Circle>(fig1)) << std::endl; 
  std::shared_ptr<Figure> fig2(new Triangle(3, 4, 5));
  std::cout << *(std::dynamic_pointer_cast<Triangle>(fig2)) << std::endl; 
  std::shared_ptr<Figure> fig3(new Square(7));
  std::cout << *(std::dynamic_pointer_cast<Square>(fig3)) << std::endl; 
 
 


//  std::shared_ptr<Figure> fig4(new Rectangle(6.9, 7.6));   /// BAD WAY we need to cast fig4 to Rectangle* ... 
//  std::cout << *fig4 << std::endl;                         /// to have access to fields of Rectangle class
	
//  Figure * fig4 = new Rectangle(6.9, 7.6);        ///  OK
//  std::cout << *((Rectangle*)fig4) << std::endl;  ///  works
//  delete fig4;                                    ///  normally
  
//  std::shared_ptr<Rectangle> rect(new Rectangle(6.9, 7.6)); /// works normally
//  std::cout << *rect << std::endl; 

  std::shared_ptr<Figure> rect(new Rectangle(6.9, 7.6));                    /// works normally, we used special casting
  std::cout << *(std::dynamic_pointer_cast<Rectangle>(rect)) << std::endl;  /// std::dynamic_pointer_cast ~ std::dynamic_cast for smart ptrs
 
  
  
  
  
  std::cout << std::endl << std::endl << std::endl;  
  Points<1> figure1 {{1, 2}};
  std::cout << figure1 << std::endl;
  Points<2> figure2 {{3,4}, {4,5}};
  std::cout << figure2 << std::endl;
  Points<3> figure3 {{1,2}, {3,4}, {5,9}};
  std::cout << figure3 << std::endl;
  Points<4> figure4 {{0,0}, {0,1}, {1,1}, {1,0}};
  std::cout << figure4 << std::endl;


  return 0;
}
