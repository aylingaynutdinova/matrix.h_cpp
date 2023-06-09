#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

class TestS21Matrix {
 public:
  TestS21Matrix() {
    matrix(0, 0) = 7, matrix(0, 1) = 8, matrix(0, 2) = 3;
    matrix(1, 0) = 5, matrix(1, 1) = 9, matrix(1, 2) = 1;
    matrix(2, 0) = 9, matrix(2, 1) = 4, matrix(2, 2) = 2;

    i_matrix(0, 0) = -0.150538, i_matrix(0, 1) = 0.0430108;
    i_matrix(0, 2) = 0.204301, i_matrix(1, 0) = 0.0107527;
    i_matrix(1, 1) = 0.139785, i_matrix(1, 2) = -0.0860215;
    i_matrix(2, 0) = 0.655914, i_matrix(2, 1) = -0.473118;
    i_matrix(2, 2) = -0.247312;

    alg_matrix(0, 0) = 14, alg_matrix(0, 1) = -1, alg_matrix(0, 2) = -61;
    alg_matrix(1, 0) = -4, alg_matrix(1, 1) = -13, alg_matrix(1, 2) = 44;
    alg_matrix(2, 0) = -19, alg_matrix(2, 1) = 8, alg_matrix(2, 2) = 23;
  }
  TestS21Matrix(int status) {
    if (status == 0) {
      matrix.setCols(2);
      matrix.setRows(2);
      matrix(0, 0) = 7, matrix(0, 1) = 8;
      matrix(1, 0) = 5, matrix(1, 1) = 9;
    }
    if (status == 1) {
    }
    if (status == 2) {
      matrix.setRows(4);
      matrix.setCols(4);
      matrix(0, 0) = 1.2, matrix(1, 0) = 10.2, matrix(2, 0) = 5.8,
                matrix(3, 0) = 2.6, matrix(0, 1) = 4.8, matrix(1, 1) = -6.7;
      matrix(2, 1) = 3.45, matrix(3, 1) = -8.9, matrix(0, 2) = -3.2;
      matrix(1, 2) = 1.9, matrix(2, 2) = -7.8, matrix(3, 2) = 2.2;
      matrix(0, 3) = 9.08, matrix(1, 3) = 9.1, matrix(2, 3) = 0.34,
                matrix(3, 3) = -1.5;
    }
    if (status == 3) {
      matrix(0, 0) = 116, matrix(0, 1) = 140, matrix(0, 2) = 35;
      matrix(1, 0) = 89, matrix(1, 1) = 125, matrix(1, 2) = 26;
      matrix(2, 0) = 101, matrix(2, 1) = 116, matrix(2, 2) = 35;
    }
    if (status == 4) {
      matrix(0, 0) = 14, matrix(0, 1) = 16, matrix(0, 2) = 6;
      matrix(1, 0) = 10, matrix(1, 1) = 18, matrix(1, 2) = 2;
      matrix(2, 0) = 18, matrix(2, 1) = 8, matrix(2, 2) = 4;
    }
    if (status == 5) {
      matrix.setCols(3);
      matrix.setRows(2);
      matrix(0, 0) = 0, matrix(0, 1) = 1, matrix(0, 2) = 2;
      matrix(1, 0) = 3, matrix(1, 1) = 4, matrix(1, 2) = 5;

      t_matrix.setCols(2);
      t_matrix.setRows(3);
      t_matrix(0, 0) = 0, t_matrix(0, 1) = 3;
      t_matrix(1, 0) = 1, t_matrix(1, 1) = 4;
      t_matrix(2, 0) = 2, t_matrix(2, 1) = 5;
    }
  }
  S21Matrix matrix = S21Matrix(3, 3);
  S21Matrix t_matrix = S21Matrix(3, 3);
  S21Matrix i_matrix = S21Matrix(3, 3);
  S21Matrix alg_matrix = S21Matrix(3, 3);
};

TEST(EqMatrixTest, HanglesInitedEqualMatrices) {
  TestS21Matrix A, B;
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(EqMatrixTest, HanglesInitedUnEqualMatrices) {
  TestS21Matrix A, B;
  B.matrix(0, 0) = A.matrix(0, 0) - 1;
  ASSERT_EQ(false, A.matrix.EqMatrix(B.matrix));
}

TEST(SumMatrixTest, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(4);
  A.matrix.SumMatrix(A.matrix);
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(SubMatrixTest, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(1);
  A.matrix.SubMatrix(A.matrix);
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(MulMatrixTest, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(3);
  A.matrix.MulMatrix(A.matrix);
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(MulNumberTest, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(4);
  A.matrix.MulNumber(2);
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(TransposeTest, HanglesInitedMatrices) {
  TestS21Matrix A(5);
  S21Matrix B = A.matrix.Transpose();
  ASSERT_EQ(true, B.EqMatrix(A.t_matrix));
}

TEST(CalcComplementsTest, HanglesInitedMatrices) {
  TestS21Matrix A;
  S21Matrix B = A.matrix.CalcComplements();
  ASSERT_EQ(true, B.EqMatrix(A.alg_matrix));
}

TEST(DeterminantTest, HanglesInitedMatrices3x3) {
  TestS21Matrix A(3);
  double determinant = A.matrix.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 8649.0);
}

TEST(MoveConstructor, HanglesInitedMatrices) {
  S21Matrix A = S21Matrix(3, 3);
  A(0, 0) = 7;
  S21Matrix B(std::move(A));
  ASSERT_EQ(true, B(0, 0) == 7);
}

TEST(DeterminantTest, HanglesInitedMatrices4x4) {
  S21Matrix A(3, 3);
  A.operator()(0, 0) = 8;
  A.operator()(0, 1) = 2;
  A.operator()(0, 2) = 4;
  A.operator()(1, 0) = 4;
  A.operator()(1, 1) = 6;
  A.operator()(1, 2) = 6;
  A.operator()(2, 0) = 4;
  A.operator()(2, 1) = 8;
  A.operator()(2, 2) = 8;
  EXPECT_EQ(16, A.Determinant());
}

TEST(InverseMatrixTest, HanglesInitedMatrices3x3) {
  TestS21Matrix A;
  S21Matrix C = A.matrix.InverseMatrix();
  for (int i = 0; i < C.getRows(); i++) {
    for (int j = 0; j < C.getCols(); j++) {
      std::cout << C(i, j) << "\t";
    }
    std::cout << std::endl;
  }
  ASSERT_EQ(true, C.EqMatrix(A.i_matrix));
}

TEST(OperatorEqual, HanglesInitedMatrices) {
  TestS21Matrix A, B;
  bool status = false;
  if (A.matrix == B.matrix) {
    status = true;
  }
  ASSERT_EQ(true, status);
}

TEST(OpetatorCopy, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(1);
  B.matrix = A.matrix;
  ASSERT_EQ(true, B.matrix.EqMatrix(A.matrix));
}

TEST(OpetatorSum, HanglesInitedMatrices) {
  TestS21Matrix A, B;
  A.matrix += B.matrix;
  B.matrix *= 2;
  ASSERT_EQ(true, B.matrix.EqMatrix(A.matrix));
}

TEST(OpetatorSub, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(1);
  A.matrix -= A.matrix;
  ASSERT_EQ(true, B.matrix.EqMatrix(A.matrix));
}

TEST(OpetatorPlus, HanglesInitedMatrices) {
  TestS21Matrix A, B;
  A.matrix = A.matrix + A.matrix;
  B.matrix *= 2;
  ASSERT_EQ(true, B.matrix.EqMatrix(A.matrix));
}

TEST(OpetatorMinus, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(1);
  A.matrix = A.matrix - A.matrix;
  ASSERT_EQ(true, B.matrix.EqMatrix(A.matrix));
}

TEST(OpetatorMulMatrices, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(3);
  A.matrix *= A.matrix;
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(OpetatorStar, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(3);
  A.matrix = A.matrix * A.matrix;
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(OperatorStar2, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(4);
  A.matrix = A.matrix * 2;
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(OpetatorMulNum, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(4);
  A.matrix *= 2;
  ASSERT_EQ(true, A.matrix.EqMatrix(B.matrix));
}

TEST(SetColRow, HanglesInitedMatrices) {
  TestS21Matrix A;
  TestS21Matrix B(0);
  A.matrix.setCols(2);
  A.matrix.setRows(2);
  ASSERT_EQ(true, A.matrix == B.matrix);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
