#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::Minor(int row_to_skip, int column_to_skip) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int result_i = 0;
  int result_j = 0;
  for (int i = 0; i < rows_ && result_i < minor.rows_; i++) {
    if (i != row_to_skip) {
      for (int j = 0; j < cols_ && result_j < minor.cols_; j++) {
        if (j != column_to_skip) {
          minor.matrix_[result_i][result_j] = matrix_[i][j];
          result_j++;
        }
      }
      result_j = 0;
      result_i++;
    }
  }
  return minor;
}

double S21Matrix::MyDeterminant() {
  double result = 0;
  if (rows_ == 1)
    result = matrix_[0][0];
  else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < cols_; i++) {
      S21Matrix sub_matrix(this->Minor(0, i));
      result += matrix_[0][i] * ((i & 1) ? -1 : 1) * sub_matrix.MyDeterminant();
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::out_of_range("Determinant cannot be calculted for this matrix");
  }
  double result = MyDeterminant();
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Cannot be calculated for this matrix");
  }
  S21Matrix result_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    int sign = (i & 1) ? -1 : 1;
    for (int j = 0; j < cols_; j++) {
      double res = 0;
      S21Matrix sub_matrix(this->Minor(i, j));
      res = sub_matrix.MyDeterminant();
      result_matrix.matrix_[i][j] = sign * res;
      sign = -sign;
    }
  }
  return result_matrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (fabs(determinant) <= 1e-6) {
    throw std::logic_error(
        "Matrix cannot be inversed, since determinant is zero");
  }
  S21Matrix transposed_matrix(this->CalcComplements().Transpose());
  transposed_matrix.MulNumber(1 / determinant);
  return transposed_matrix;
}
