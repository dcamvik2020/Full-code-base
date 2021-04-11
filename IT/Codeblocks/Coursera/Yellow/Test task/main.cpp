/// Task : to create a class Matrix and operation
/// + for matrixes A, B

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
        /// default size of vector = 0, but...
        ///matrix.assign()
    }

    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }

    /// Reset makes all element of matrix = 0
    void Reset(int new_rows, int new_cols) {
        if (new_rows < 0) {
            throw  out_of_range("num_rows must be >= 0");
        }
        if (new_cols < 0) {
            throw  out_of_range("num_columns must be >= 0");
        }

        if (new_rows == 0 || new_cols == 0) {
            new_rows = new_cols = 0;
        }

        rows = new_rows;
        cols = new_cols;

        /// {} - empty vector
        matrix.assign(new_rows, vector<int> (new_cols));
        //matrix.assign(new_rows, {});
        //for (int i = 0; i < new_rows; ++i) {
        //    matrix[i].assign(new_cols, 0);
        //}
    }

    /// At takes INDEXES (from 0 to    ... - 1)
    int At(int row, int col) const {
        /// it is unnecessary
        /*if (row < 0 || rows <= row ||
            col < 0 || cols <= col) {
/*
            string error;
            if (row < 0) error += "row < 0     ";
            if (rows <= row) error += "rows <= row     ";
            if (col < 0) error += "col < 0     ";
            if (cols <= col) error += "cols <= col     ";

            //throw  out_of_range("int At() ----> errors : " + error);
            throw  out_of_range("int At()");
        } */
        return matrix.at(row).at(col);
    }

    /// we need to overload --> change arguments
    int& At(int row, int col) {
        /// it is unnecessary
        /*if (row < 0 || rows <= row ||
            col < 0 || cols <= col) {
            throw  out_of_range("int& At()");
        }*/
        return matrix.at(row).at(col);
    }

    int GetNumRows() const {return rows;}
    int GetNumColumns() const {return cols;}

private:
    int rows;
    int cols;
    vector<vector<int>> matrix;
};

Matrix operator + (const Matrix& A, const Matrix& B) {
    if (A.GetNumRows() != B.GetNumRows()) {
        throw invalid_argument("");
    }
    if (A.GetNumColumns() != B.GetNumColumns()) {
        throw invalid_argument("");
    }
    int rows = A.GetNumRows(), cols = A.GetNumColumns();
    Matrix tmp(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.At(i, j) =  A.At(i, j) + B.At(i, j);
        }
    }
    return tmp;
}

bool operator == (const Matrix& A, const Matrix& B) {
    if (A.GetNumRows() == B.GetNumRows()) {
        if (A.GetNumColumns() == B.GetNumColumns()) {
            int rows = A.GetNumRows();
            int cols = A.GetNumColumns();
            for (int i = 0 ; i < rows; ++i) {
                for (int j = 0 ; j < cols; ++j) {
                    if (A.At(i, j)!= B.At(i, j)) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return false;
}

istream& operator >> (istream& input, Matrix& A) {
    /// suppose that input is correct
    int rows, cols;
    input >> rows >> cols;
    A.Reset(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            input >> A.At(i, j);
        }
    }
    return input;
}

ostream& operator << (ostream& output, const Matrix& A) {
    output << A.GetNumRows() << " " << A.GetNumColumns() << endl;
    for (int i = 0; i < A.GetNumRows(); ++i) {
        for (int j = 0; j < A.GetNumColumns(); ++j) {
            output << A.At(i, j);
            if (j < A.GetNumColumns() - 1) output << " ";
        }
        output << endl;
    }
    return output;
}

int main() {

    Matrix one;
    Matrix two;

    //try {
      cin >> one >> two;
      cout << one + two << endl;
    /*} catch (invalid_argument& ia) {
        cout << "Caught invalid argument: " << ia.what() << endl;
    } catch (out_of_range& oor) {
        cout << "Caught invalid argument: " << oor.what() << endl;
    }*/
    return 0;
}
