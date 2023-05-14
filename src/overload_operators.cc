#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result_matrix(*this);
  result_matrix.SumMatrix(other);
  return result_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result_matrix(*this);
  result_matrix.SubMatrix(other);
  return result_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result_matrix(*this);
  result_matrix.MulMatrix(other);
  return result_matrix;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result_matrix(*this);
  result_matrix.MulNumber(num);
  return result_matrix;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->~S21Matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    MemoryAllocation();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("1 row or column number out of size");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("two rows or column number out of size");
  }
  return matrix_[row][col];
}