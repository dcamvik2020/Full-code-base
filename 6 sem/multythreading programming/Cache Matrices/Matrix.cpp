#include "Matrix.h"

Matrix::Matrix(const std::string & _name, unsigned _h, unsigned _w, bool random_fill)
        : name(_name), h(_h), w(_w), matr(std::vector<std::vector<int>> (h, std::vector<int>(w, 0))) {
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
  } else {
    /// fill with default value = 0
    /// it's done in inializer list
  }
  blocking();
}



Matrix::Matrix(const Matrix & other) : name(other.getName()), h(other.getHeight()), w(other.getWidth()) {
  for (unsigned i = 0; i < h; ++i) {
    for (unsigned j = 0; j < w; ++j) {
      matr[i][j] = other[i][j];
    }
  }
  blocking();
}



void Matrix::blocking () {
  unsigned new_h = h / BLOCK_H;
  unsigned new_w = w / BLOCK_W;
  std::vector<MatrixBlock> row_blocks(new_w);

  for (unsigned i = 0; i < new_h; ++i) { 
    for (unsigned j = 0; j < new_w; ++j) {
      MatrixBlock & cur_block = row_blocks[j]; 
      for (unsigned k = 0; k < BLOCK_H;	++k) {
        for (unsigned l = 0; l < BLOCK_W; ++l) {
          cur_block[k][l] = matr[i * BLOCK_H + k][j * BLOCK_W + l];
        }
      }
    }

    blocked_matr.push_back(row_blocks);
  }
}



void Matrix::unblocking () {
  unsigned new_h = h / BLOCK_H;
  unsigned new_w = w / BLOCK_W;
  for (unsigned i = 0; i < new_h; ++i) {
    for (unsigned j = 0; j < new_w; ++j) {
      unsigned y_offset = i * BLOCK_H;
      unsigned x_offset = j * BLOCK_W;	
      MatrixBlock & cur_block = blocked_matr[i][j]; 
      for (unsigned k = 0; k < BLOCK_H;	++k) {
        for (unsigned l = 0; l < BLOCK_W; ++l) {
          matr[y_offset + k][x_offset + l] = cur_block[k][l];
        }
      }
    }
  }
}



void Matrix::printMatrix() const {
  std::cout << "Matrix " << name << " : \n";
  for (unsigned i = 0; i < h; ++i) {
    for (unsigned j = 0; j < w; ++j) {
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
  for (unsigned i = 0; i < h; ++i) {
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



Matrix mul (const Matrix & lhs, const Matrix & rhs, unsigned threads){
  Matrix ans("answer", lhs.getHeight(), rhs.getWidth(), false);
  
  /// (const) std::vector<std::vector<MatrixBlock>> &
  auto & A_blocked = lhs.getBlockedMatrix();        
  auto & B_blocked = rhs.getBlockedMatrix();
  auto & C_blocked = ans.getBlockedMatrix(); /// see Matrix constructor
 
  unsigned N = lhs.getHeight() / BLOCK_H;
  unsigned M = lhs.getWidth() / BLOCK_W;
  unsigned K = rhs.getWidth() / BLOCK_W;

  /// job for each thread
  /// first, last rows of blocks for thread in matrix A
  auto job = [&](unsigned first_row, unsigned last_row) {
    Matrix::MatrixBlock tmp;
    for (unsigned i = first_row; i < last_row; i++) {
      for (unsigned k = 0; k < M; k++) {
        tmp = A_blocked[i][k];
        for (unsigned j = 0; j < K; j++) {
          C_blocked[i][j] += tmp * B_blocked[k][j];
        }	
      }
    }
  };

  /// split rows to threads
  if (threads > 1) {
    std::vector<std::thread> T;
    const unsigned rows_per_thread = N / threads;
    for (unsigned tid = 0; tid < threads; ++tid) {
      unsigned first_row = rows_per_thread * tid;
      unsigned last_row = (tid == threads - 1) ? N : rows_per_thread * (tid + 1);
      T.push_back( std::thread(job, first_row, last_row) );
    }
    for (unsigned i = 0; i < T.size(); ++i) {
      T[i].join();
    }
  } else {
    //std::cout << "thread = 1\n";
    job(0, N);   
  }	  
  
  ans.unblocking();
  
  return ans;
}



/// A <--> M * N
/// B <--> N * K
/// C <--> M * K
/// last_line -- not included (i.e. [first, last) interval)
void mul_func(unsigned first_row, unsigned last_row, const Matrix & A, unsigned N, const Matrix & B, unsigned K, Matrix & C) {
  for (unsigned i = first_row; i < last_row; ++i) {
    for (unsigned k = 0; k < N; ++k) {
      int x = A[i][k];
      for (unsigned j = 0; j < K; ++j) {
        C[i][j] += x * B[k][j];
      }
    }
  }
}
