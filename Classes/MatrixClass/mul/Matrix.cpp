#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

#include "Matrix.h"

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

Matrix operator * (const Matrix& a, const Matrix& b) {
    unsigned n = a.rows, m = a.cols;
    unsigned x = b.rows, y = b.cols;

    if (m != x) {
        throw std::invalid_argument("");
    }

    Matrix c(n, y);
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < y; ++j) {
            for (unsigned k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
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
    in >> n >> m;

    if (n == 0 || m == 0) {
        throw std::invalid_argument("");
    }

    /// x can be created by : Matrix x; --> rows = cols = 0
    /// x.Rows() == 0  <-->  x.Cols() == 0
    if (x.Rows() == 0) {
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


