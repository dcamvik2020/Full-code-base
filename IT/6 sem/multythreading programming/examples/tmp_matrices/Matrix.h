#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

#include <random>


/// sizes will be likw 4 * k, k = natural
class Matrix {
private:
  const std::string name;
  unsigned w, h;
  std::vector<std::vector<int>> matr;
  
public:
  Matrix(const std::string & _name, unsigned _w = 0, unsigned _h = 0, bool random_fill = true);
  
  unsigned getHeight() const {return h;}
  unsigned getWidth() const {return w;}

  std::vector<int> & operator [] (unsigned i) {return matr[i];}
  const std::vector<int> & operator [] (unsigned i) const {return matr[i];}
  
  Matrix & operator = (const Matrix & other);
  bool operator == (const Matrix & other) const;

  void printMatrix() const;

  ~Matrix() {}

private:
  /// block is 4*4 matrix
  class MatrixBlock {
  private:
    int block[4][4] = {{0}};
  public:
    MatrixBlock() {}
    MatrixBlock(const int (& some_data) [4][4]);
   
    int* operator [] (unsigned i) {return block[i];}
    const int* operator [] (unsigned i) const {return block[i];}

    MatrixBlock operator * (const MatrixBlock & other);

    ~MatrixBlock() {}
  };

};

void mul_func(unsigned first_row, unsigned last_row, const Matrix & A, const Matrix & B, Matrix & C, unsigned size);

#endif
