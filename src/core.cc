#include "s21_matrix_oop.h"

void S21Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  MemoryAllocation();
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = cols_ = 0;
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 0 || cols < 0) {
    throw ::out_of_range(
        "Incorrect input, rows and columns should be more than 0");
  }
  MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  if (!other.matrix_ || other.cols_ < 0 || other.rows_ < 0) {
    throw ::out_of_range("Incorrect input");
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  MemoryAllocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {
  S21Matrix tmp_matrix(rows, cols_);
  for (int i = 0; i < tmp_matrix.rows_; i++) {
    std::memcpy(tmp_matrix.matrix_[i], matrix_[i],
                cols_ * sizeof(double));
  }
  *this = tmp_matrix;
}

void S21Matrix::setCols(int cols) {
  S21Matrix tmp_matrix(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    std::memcpy(tmp_matrix.matrix_[i], matrix_[i],
                tmp_matrix.cols_ * sizeof(double));
  }
  *this = tmp_matrix;
}
