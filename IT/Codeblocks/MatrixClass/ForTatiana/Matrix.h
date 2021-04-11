#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

#include "Vector.h"
#define cor0(x) (((x) > -1e-10 && (x) < 1e-10) ? T() : (x))


template <class T>
class Matrix {
private:
    unsigned rows;
    unsigned cols;
    Vector<Vector<T>> a;
    const T zero = T();
    const T one  = T(1);
public:

    Matrix() : rows(0), cols(0), a(0) {}
    Matrix(unsigned n, unsigned m, T element = T());
    Matrix(const Matrix<T>& x);
    void operator = (const Matrix<T>& x);
    void MakeAccuracy();


    bool IsSquare() {return (rows == cols) ? true : false;}
    unsigned Rows() const {return rows;}
    unsigned Cols() const {return cols;}
    void resize(unsigned n = 0, unsigned m = 0);


    T& at (unsigned i, unsigned j) const;
    Vector<T>& operator [] (unsigned i) const;


    friend Matrix<T> operator + (const Matrix<T>& a, const Matrix<T>& b) {
        if (a.rows != b.rows ||
            a.cols != b.cols) {
            throw std::invalid_argument("");
        }
        unsigned n = a.rows, m = a.cols;
        Matrix<T> tmp(a);
        for (unsigned i = 0; i < n; ++i) {
            for (unsigned j = 0; j < m; ++j) {
                tmp[i][j] += b[i][j];
            }
        }
        return tmp;
    }
    friend Matrix<T> operator - (const Matrix<T>& a, const Matrix<T>& b) {
        if (a.rows != b.rows ||
            a.cols != b.cols) {
            throw std::invalid_argument("");
        }
        unsigned n = a.rows, m = a.cols;
        Matrix<T> tmp(a);
        for (unsigned i = 0; i < n; ++i) {
            for (unsigned j = 0; j < m; ++j) {
                tmp[i][j] -= b[i][j];
            }
        }
        return tmp;
    }
    friend Matrix<T> operator * (const Matrix<T>& a, const Matrix<T>& b) {
        unsigned n = a.rows, m = a.cols;
        unsigned x = b.rows, y = b.cols;

        if (m != x) {
            throw std::invalid_argument("");
        }

        Matrix<T> c(n, y);
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < y; ++j) {
                for (unsigned k = 0; k < m; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    T tr() const;
    T det() const;
    Matrix<T> inversed() const;


    friend std::istream& operator >> (std::istream& in, Matrix<T>& x) {
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
    friend std::ostream& operator << (std::ostream& out, const Matrix<T>& x) {
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

    ~Matrix() {
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
};

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
void Matrix<T>::MakeAccuracy() {
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            a[i][j] = cor0(abs(a[i][j]));
	}
    }
}


template <class T>
void Matrix<T>::resize(unsigned n, unsigned m) {
    if ((n == 0 && m != 0) || (m == 0 && n != 0)) {
        throw std::invalid_argument("");
    }

    //for (unsigned i = 0; i < rows; ++i) {
    //    delete &a[i];
    //

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





template <class T>
Matrix<T> Matrix<T>::inversed() const {
    //unsigned rows = A.Rows(), cols = A.Cols();
    if (rows != cols) {
        throw std::invalid_argument("Wrong matrix size");
    }

    /// create matrix with 2 parts: left is A,
    /// right part is just E-matrix
    Matrix<T> tmp(rows, 2 * cols);
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            tmp[i][j] = a[i][j];
        }
        tmp[i][i + cols] = one;
    }

    T x;
    Vector<T> row;
    /// all under and over main diagonal = 0
    /// left->right
    for (unsigned i = 0; i < rows; i++) {

        ///no null elements on main diagonal
        if (!cor0(abs(tmp[i][i]))) {
            unsigned j;
            for (j = i + 1; j < cols && (!cor0(abs(tmp[j][i]))); j++);
            if (j == cols) {
                throw std::runtime_error("Too many zeros for inversion");
            }
            std::swap(tmp[i], tmp[j]);
        }

        ///now tmp[i][i] != 0 -> do it = 1
        x = tmp[i][i];
        for (unsigned k = i; k < 2 * cols; k++) {
            tmp[i][k] /= x;
        }

        ///now tmp[i][i] = 1, go up->down
        for (unsigned j = 0; j < rows; j++) {
            if (j != i) {
                x = tmp[j][i];
                for (unsigned k = i; k < 2 * cols; k++){
                    tmp[j][k] -= x * tmp[i][k];
                }
                ///now tmp[j][i] = 0
            }
        }
    }

    Matrix<T> res(rows, cols);
    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            res[i][j] = tmp[i][j + cols];
        }
    }
    return res;
}
