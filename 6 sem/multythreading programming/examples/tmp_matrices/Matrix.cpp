#include "Matrix.h"

Matrix::Matrix(const std::string & _name, unsigned _w, unsigned _h, bool random_fill)
        : name(_name), w(_w), h(_h), matr(std::vector<std::vector<int>> (h, std::vector<int>(w))) {
  if (random_fill) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10); // distribution in range [1, 6]
    //std::cout << dist10(rng) << std::endl;
    for (unsigned i = 0; i < h; ++i) {
      for (unsigned j = 0; j < w; ++j) {
        matr[i][j] = dist10(rng);
      }
    }
  }
}



void Matrix::printMatrix() const {
  std::cout << "Matrix " << name << " : \n";
  for (unsigned i = 0; i < w; ++i) {
    for (unsigned j = 0; j < h; ++j) {
      std::cout << matr[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}



Matrix & Matrix::operator = (const Matrix & other) {
  h = other.getHeight();
  w = other.getWidth();
  matr.resize(h);
  for (unsigned i = 0; i < h; ++h) {
    matr.resize(w);
    for (unsigned j = 0; j < w; ++j) {
      matr[i][j] = other[i][j];
    }
  }
  return *this;
}



bool Matrix::operator == (const Matrix & other) const {
  if (w != other.getWidth() || h != other.getHeight()) 
    return false;
  for (unsigned i = 0; i < other.getHeight(); ++i) {
    for (unsigned j = 0; j < other.getWidth(); ++j) {
      if (matr[i][j] != other[i][j]) return false;
    }
  }
  return true;
}



Matrix::MatrixBlock::MatrixBlock(const int (& some_data) [4][4]) {
  for (unsigned i = 0; i < 4; ++i) {
    for (unsigned j = 0; j < 4; ++j) {
      block[i][j] = some_data[i][j];
    }
  }
}



Matrix::MatrixBlock Matrix::MatrixBlock::operator * (const MatrixBlock & other) {
  MatrixBlock result;
  for (unsigned i = 0; i < 4; ++i) {
    for (unsigned k = 0; k < 4; ++k) {
      int x = block[i][k];
      for (unsigned j = 0; j < 4; ++j) {
        result[i][j] += x * other[k][j];
      }
    }
  }
  return result;
}



/// A, B, C -- square matrices
/// B is transposed
/// last_line -- not included (i.e. [first, last) interval)
void mul_func(unsigned first_row, unsigned last_row, const Matrix & A, const Matrix & B, Matrix & C, unsigned size) {
  for (unsigned i = first_row; i < last_row; ++i) {
    for (unsigned j = 0; j < size; ++j) {
      C[i][j] = 0;
      for (unsigned k = 0; k < size; ++k) {
        C[i][j] += A[i][k] * B[j][k];
      }
    }
  }
}
