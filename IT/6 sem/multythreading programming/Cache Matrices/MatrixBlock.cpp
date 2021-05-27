#include "Matrix.h"


std::ostream & operator << (std::ostream & out, const Matrix::MatrixBlock & other) {
  out << "Block in matrix " << other.getMatrName() << " : \n";
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    for (unsigned j = 0; j < BLOCK_W; ++j) {
      out << other[i][j] << " ";
    }
    out << "\n";
  }
  out << "\n";
  return out;
}



Matrix::MatrixBlock::MatrixBlock(const Matrix::MatrixBlock & other) : matr_name(other.matr_name) {
  //block.resize(BLOCK_H);
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    //block.resize(BLOCK_W);
    for (unsigned j = 0; j < BLOCK_W; ++j) {
      block[i][j] = other[i][j];
    }
  }
}


Matrix::MatrixBlock::MatrixBlock(const int (& some_data) [4][4], const std::string & _matr_name) : matr_name(_matr_name) {
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    for (unsigned j = 0; j < BLOCK_W; ++j) {
      block[i][j] = some_data[i][j];
    }
  }
}



Matrix::MatrixBlock Matrix::MatrixBlock::operator * (const MatrixBlock & other) {
	//std::cout << "\t\tmatrix blocks mul start\n";
  MatrixBlock result;
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    for (unsigned k = 0; k < BLOCK_W; ++k) {
      int x = block[i][k];
      for (unsigned j = 0; j < BLOCK_W; ++j) {
        result[i][j] += x * other[k][j];
      }
    }
  }
        //std::cout << "\t\tmatrix blocks mul stop\n";
  return result;
}



Matrix::MatrixBlock & Matrix::MatrixBlock::operator += (const MatrixBlock & other) {
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    for (unsigned j = 0; j < BLOCK_W; ++j) {
      block[i][j] += other[i][j];
    }
  } 
  return *this;
}


Matrix::MatrixBlock & Matrix::MatrixBlock::operator = (const Matrix::MatrixBlock & other) {
  //block.resize(BLOCK_H);
  for (unsigned i = 0; i < BLOCK_H; ++i) {
    //block.resize(BLOCK_W);
    for (unsigned j = 0; j < BLOCK_W; ++j) {
      block[i][j] = other[i][j];
    }
  }
  return *this;
}




