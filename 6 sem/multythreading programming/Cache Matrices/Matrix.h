#pragma once

#include <iostream>
#include <vector>

#include <thread>
#include <random>


#include <sstream>
#include <fstream>
#include "tools.h"


#define BLOCK_W 16
#define BLOCK_H 16


/// sizes will be good : they will be divided in blocks without rest
class Matrix {
private:
  const std::string name;
  unsigned h, w;
  std::vector<std::vector<int>> matr;
  
public:
  Matrix(const std::string & _name, unsigned _h = 0, unsigned _w = 0, bool random_fill = true);
  Matrix(const Matrix & other); 

  const std::string & getName() const {return name;}
  unsigned getHeight() const {return h;}
  unsigned getWidth() const {return w;}

  std::vector<int> & operator [] (unsigned i) {return matr[i];}
  const std::vector<int> & operator [] (unsigned i) const {return matr[i];}
  
  Matrix & operator = (const Matrix & other);
  bool operator == (const Matrix & other) const;

  void printMatrix() const;

  ~Matrix() {}

private:
  class MatrixBlock {
  private:
    int block[BLOCK_H][BLOCK_W] = {{0}};
    const std::string matr_name;
  public:
    MatrixBlock() {}
    MatrixBlock(const MatrixBlock & other);
    MatrixBlock(const int (& some_data) [BLOCK_H][BLOCK_W], const std::string & _matr_name = "unknown");
   
    int* operator [] (unsigned i) {return block[i];}
    const int* operator [] (unsigned i) const {return block[i];}
    std::string getMatrName() const {return matr_name;}

    MatrixBlock operator * (const MatrixBlock & other);
    MatrixBlock & operator += (const MatrixBlock & other);
    MatrixBlock & operator = (const MatrixBlock & other);

    ~MatrixBlock() {}
  };

  std::vector<std::vector<MatrixBlock>> blocked_matr;
  void blocking ();
  void unblocking ();

public: 
  friend Matrix mul (const Matrix & lhs, const Matrix & rhs, unsigned threads);
  friend std::ostream & operator << (std::ostream & out, const MatrixBlock & other);
  
  std::vector<std::vector<MatrixBlock>> & getBlockedMatrix() {return blocked_matr;}
  const std::vector<std::vector<MatrixBlock>> & getBlockedMatrix() const {return blocked_matr;}
};

void mul_func(unsigned first_row, unsigned last_row, const Matrix & A, unsigned N, const Matrix & B, unsigned K, Matrix & C);
