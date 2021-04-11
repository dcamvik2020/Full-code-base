#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

#include "Vector.h"

class Matrix {
private:
    unsigned rows;
    unsigned cols;
    Vector<Vector<int>> a;
public:
    Matrix() : rows(0), cols(0), a(0) {}
    Matrix(unsigned n, unsigned m, int element = 0);
    Matrix(const Matrix& x);
    void operator = (const Matrix& x);


    bool IsSquare() {return (rows == cols) ? true : false;}
    unsigned Rows() const {return rows;}
    unsigned Cols() const {return cols;}
    void resize(unsigned n = 0, unsigned m = 0);


    int& at (unsigned i, unsigned j) const;
    Vector<int>& operator [] (unsigned i) const;


    friend Matrix operator + (const Matrix& a, const Matrix& b);
    friend Matrix operator - (const Matrix& a, const Matrix& b);
    friend Matrix operator * (const Matrix& a, const Matrix& b);


    int tr() const;


    friend std::istream& operator >> (std::istream& in, Matrix& x);
    friend std::ostream& operator << (std::ostream& out, const Matrix& x);


    ~Matrix();
};
