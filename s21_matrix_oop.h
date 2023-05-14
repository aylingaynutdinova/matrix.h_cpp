#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class S21Matrix {
 public:
  S21Matrix();                        // Default constructor
  S21Matrix(int rows, int cols);      // Parametrized constructor
  S21Matrix(const S21Matrix& other);  // Copy constructor
  S21Matrix(S21Matrix&& other);       // Move constructor
  ~S21Matrix();                       // Destructor

  // Methods
  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Accessors
  int getRows() const;
  int getCols() const;

  // Mutators
  void setRows(int rows);
  void setCols(int cols);

  // Overload operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double num) const;
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  double& operator()(int row, int col);
  double operator()(int row, int col) const;

 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  void MemoryAllocation();
  double MyDeterminant();
  S21Matrix Minor(int row_to_skip, int column_to_skip);
};

#endif /* CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H */