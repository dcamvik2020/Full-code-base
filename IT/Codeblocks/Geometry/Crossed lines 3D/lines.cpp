#include <iostream>
//#include "Matrix.h"
#include <cmath>

using namespace std;

#define cor_0(x) ((std::abs(x) < 1e-6) ? (0) : (x))



struct Point {
  int x, y, z;
  Point() {}
  explicit Point(int x_0, int y_0, int z_0) 
	  : x(x_0), y(y_0), z(z_0) {}
  bool operator == (const Point & rhs) {
    if (x == rhs.x) {
      if (y == rhs.y) {
        return z == rhs.z;
      }
    }
    return false;
  }
  double vector_len() const {return sqrtf(x*x + y*y + z*z);}
};

Point operator - (const Point & lhs, const Point & rhs) {
  return Point(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}
Point & operator /= (Point & lhs, double p) {
  if (cor_0(p) == 0) throw "Div by zero";
  lhs.x /= p, lhs.y /= p, lhs.z /= p;
  return lhs;
}
Point operator / (Point lhs, double p) {
  return lhs /= p;
}
std::istream & operator >> (std::istream & is, Point & p) {
  return is >> p.x >> p.y >> p.z;
}





struct Line {
  Point A, B;
  Line() {}
  explicit Line(const Point & A_0, const Point & B_0) 
	  : A(A_0), B(B_0) {
    if (A == B) throw "Can't create a line through A, B";
  }
  bool operator == (const Line & rhs) {
    double len_1 = (B - A).vector_len();
    double len_2 = (rhs.B - rhs.A).vector_len();
    Point gradient_1((B - A) / len_1);
    Point gradient_2((rhs.B - rhs.A) / len_2);
    
    if (cor_0(gradient_1.x - gradient_2.x) == 0 &&
        cor_0(gradient_1.y - gradient_2.y) == 0 &&
        cor_0(gradient_1.z - gradient_2.z) == 0) {
      return true;
    }
    return false;
  }
};






bool AreLinesCrossed(const Line & line_1, const Line & line_2);

int main() {
  
  Point A1, B1; 
  cout << "line 1 goes through points A1, B1 :" << endl;
  cout << "A1 : "; cin >> A1;
  cout << "B1 : "; cin >> B1;

  Point A2, B2;
  cout << "line 2 goes through points A2, B2:" << endl;
  cout << "A2 : "; cin >> A2;
  cout << "B2 : "; cin >> B2;

  /// are the lines crossed ? 
  Line line_1(A1, B1), line_2(A2, B2); 
  cout << AreLinesCrossed(line_1, line_2) << endl;

  return 0;
}

bool AreLinesCrossed(const Line & line_1, const Line & line_2) {
  if (line_1 == line_2) {
    return 
  }
}
