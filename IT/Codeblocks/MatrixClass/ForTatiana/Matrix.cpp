#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(unsigned n, unsigned m, T element) {
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

template <class T>
Matrix<T>::Matrix(const Matrix<T>& x) {
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

template <class T>
void Matrix<T>::operator = (const Matrix<T>& x) {
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

template <class T>
void Matrix<T>::resize(unsigned n, unsigned m) {
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
            a[i][j] = (T)0;
        }
    }
}

template <class T>
T& Matrix<T>::at (unsigned i, unsigned j) const {
    if (i >= rows || j >= cols) {
        throw std::invalid_argument("");
    }
    return a[i][j];
}

template <class T>
Vector<T>& Matrix<T>::operator [] (unsigned i) const {
    if (i >= rows) {
        throw std::invalid_argument("");
    }
    return a[i];
}




template <class T>
T Matrix<T>::tr() const {
    if (rows != cols) {
        throw std::runtime_error("Wrong matrix size!");
    }

    T sum = 0;
    for (unsigned i = 0; i < rows; ++i) {
        sum += a[i][i];
    }
    return sum;
}

template <class T>
T Matrix<T>::det() const {
    if (rows == 0 || cols == 0 || rows != cols)
        throw std::invalid_argument("Error size of matrix");
    if (rows == 1)
        return a[0][0];

    T res = 0;
    int k = 1; /// (-1)^n
    /// smaller matrix, (n-1)*(n-1) -->
    /// use standard formula for det(A)
    Matrix<T> p(rows - 1, cols - 1);

    for (unsigned i = 0; i < rows; i++) {
        unsigned x, y, dx, dy;
        dy = 0;
        for (x = 0; x < rows - 1; x++) {
            dx = 0;
            if (x == 0) {
                dy = 1;
            }
            for (y = 0; y < rows - 1; y++) {
                if (y == i)
                    dx = 1;
                p[x][y] = a[x+dy][y+dx];
            }
        }
        res += k * a[0][i] * p.det();
        k = -k; /// like in standard formula
    }
    return res;
}
