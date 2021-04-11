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


    int tr() const;


    friend std::istream& operator >> (std::istream& in, Matrix& x);
    friend std::ostream& operator << (std::ostream& out, const Matrix& x);


    ~Matrix();
};

Matrix::Matrix(unsigned n, unsigned m, int element) {
    if ((n == 0 && m != 0) || (m == 0 && n != 0)) {
        throw std::invalid_argument("");
    }
    if (n == 0 && m == 0) {
        Matrix();
    }
    rows = n;
    cols = m;
    a.resize(rows);
    for (unsigned i = 0; i < rows; ++i) {
        a[i].resize(cols);
        for (unsigned j = 0; j < cols; ++j) {
            a[i][j] = element;
        }
    }
}

Matrix::Matrix(const Matrix& x) {
    if (x.rows == 0 &&  x.cols == 0) {
        Matrix();
    }
    if (x.rows == 0 ||  x.cols == 0) {
        throw std::invalid_argument("");
    }
    rows = x.rows;
    cols = x.cols;
    a.resize(rows);
    for (unsigned i = 0; i < rows; ++i) {
        a[i].resize(cols);
        for (unsigned j = 0; j < cols; ++j) {
            a[i][j] = x[i][j];
        }
    }
}

void Matrix::operator = (const Matrix& x) {
    if (rows != 0) {
        if (rows != x.rows ||  cols != x.cols) {
            throw std::invalid_argument("");
        }
    }
    if (rows == 0) {
        rows = x.rows;
        cols = x.cols;
        a.resize(rows);
        for (unsigned i = 0; i < rows; ++i) {
            a[i].resize(cols);
        }
    }
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            a[i][j] = x[i][j];
        }
    }
}

void Matrix::resize(unsigned n, unsigned m) {
    if ((n == 0 && m != 0) || (m == 0 && n != 0)) {
        throw std::invalid_argument("");
    }

    /*for (unsigned i = 0; i < rows; ++i) {
        delete &a[i];
    }*/

    /// delete every a[i] --> error because
    /// next line will try to do it again
    ///      it's bad idea to delete <vector>
    /// delete &a;

    /// resize will delete vector in a good way
    rows = n;
    cols = m;
    a.resize(rows);
    for (unsigned i = 0; i < rows; ++i) {
        a[i].resize(cols);
        for (unsigned j = 0; j < cols; ++j) {
            a[i][j] = 0;
        }
    }
}

int& Matrix::at (unsigned i, unsigned j) const {
    if (i >= rows || j >= cols) {
        throw std::invalid_argument("");
    }
    return a[i][j];
}

Vector<int>& Matrix::operator [] (unsigned i) const {
    if (i >= rows) {
        throw std::invalid_argument("");
    }
    return a[i];
}




Matrix operator + (const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows ||
        a.cols != b.cols) {
        throw std::invalid_argument("");
    }
    unsigned n = a.rows, m = a.cols;
    Matrix tmp(a);
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            tmp[i][j] += b[i][j];
        }
    }
    return tmp;
}

Matrix operator - (const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows ||
        a.cols != b.cols) {
        throw std::invalid_argument("");
    }
    unsigned n = a.rows, m = a.cols;
    Matrix tmp(a);
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            tmp[i][j] -= b[i][j];
        }
    }
    return tmp;
}



int Matrix::tr() const {
    if (rows != cols) {
        throw std::runtime_error("Wrong matrix size!");
    }

    int sum = 0;
    for (unsigned i = 0; i < rows; ++i) {
        sum += a[i][i];
    }
    return sum;
}



std::istream& operator >> (std::istream& in, Matrix& x) {
    unsigned n, m;
    //if (in == std::cin) {}
    in >> n >> m;

    if (n == 0 || m == 0) {
        throw std::invalid_argument("");
    }

    /// x can be created by : Matrix x; --> rows = cols = 0
    /// x.Rows() == 0  <-->  x.Cols() == 0
    if (x.rows == 0) {
        x.resize(n, m);
    } else {
        if (x.Rows() != n || x.Cols() != m) {
            throw std::invalid_argument("");
        }
    }

    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            in >> x[i][j];
        }
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Matrix& x) {
    out << "rows = " << x.Rows() << endl;
    out << "cols = " << x.Cols() << endl;
    out << "matrix : " << endl;
    for (unsigned i = 0; i < x.Rows(); ++i) {
        for (unsigned j = 0; j < x.Cols(); ++j) {
            out << x[i][j] << " ";
        }
        if (i != x.Rows() - 1) {
            out << endl;
        }
    }
    return out;
}

Matrix::~Matrix() {
    ///cout << "Matrix Destructor" << endl;
    /*for (unsigned i = 0; i < rows; ++i) {
        delete &a[i];
    }*/

    /// delete every a[i] --> error because
    /// next line will try to do it again

    ///vector will be deleted automatically!!!!!
    ///delete a;
    //a = NULL;
}




int main() {
    Matrix a(2, 2, 1), b(2, 2, 1), c;

    cout << "                       1" << endl;
    cout << a + b << endl;
    cout << "                       2" << endl;
    cout << a - b << endl;

    cout << "                       3" << endl;
    c = a;
    cout << "                       4" << endl;
    c.resize(3, 4);
    cout << "                       5" << endl;
    c.resize(0, 0);
    //cout << "\nC : \n" << c << endl;

    //cout << "c.tr() = " << c.tr() << endl;

    /*cout << "c.resize(3, 4): in" << endl;
     *c.resize(3, 4);
     *cout << c << endl;
     *cout << "c.resize(3, 4): out" << endl;
     */



    return 0;
}
