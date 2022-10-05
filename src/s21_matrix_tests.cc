#include "s21_matrix_oop.h"
#include <cstdlib>
#include "gtest/gtest.h"

void randm(S21Matrix& m) {
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getCols(); j++)
            m(i, j) = rand() % 10;
}

void printm(S21Matrix& m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++)
            std::cout << m(i, j) << " ";
        std::cout << std::endl;
    }
}

TEST(test, EqMatrix_1) {
    S21Matrix josky, flex;
    for (auto i = 0; i < josky.getRows(); i++) {
        for (auto j = 0; j<josky.getCols(); j++) {
            josky(i, j) = 1;
            flex(i, j) = 1;
        }
    }
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, EqMatrix_2) {
    S21Matrix josky, flex;
    josky(2, 2) = 1;
    EXPECT_FALSE(josky.EqMatrix(flex));
}

TEST(test, SumMatrix_1) {
    S21Matrix josky(2, 2);
    josky(0, 0) = 2;
    josky(0, 1) = 4;
    josky(1, 0) = 6;
    josky(1, 1) = 8;
    S21Matrix flex = josky * 2;
    josky.SumMatrix(josky);
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, SumMatrix_2) {
    S21Matrix josky(2, 3), flex;
    EXPECT_THROW(josky.SumMatrix(flex), std::out_of_range);
}

TEST(test, SubMatrix_1) {
    S21Matrix josky(2, 2), flex(2, 2);
    josky(0, 0) = 2;
    josky(0, 1) = 4;
    josky(1, 0) = 6;
    josky(1, 1) = 8;
    josky.SubMatrix(josky);
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, SubMatrix_2) {
    S21Matrix josky(2, 2), flex(2, 2);
    josky(0, 0) = 2;
    josky(0, 1) = 4;
    josky(1, 0) = 6;
    josky(1, 1) = 8;
    flex.SubMatrix(josky);
    josky *= -1;
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, MulNumber_1) {
    S21Matrix josky(2, 2), flex;
    josky(0, 0) = 2;
    josky(0, 1) = 4;
    josky(1, 0) = 6;
    josky(1, 1) = 8;
    flex = josky;
    josky.MulNumber(2);
    flex += flex;
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, MulNumber_2) {
    S21Matrix josky(2, 2), flex(2, 2);
    josky(0, 0) = 2;
    josky(0, 1) = 4;
    josky(1, 0) = 6;
    josky(1, 1) = 8;
    josky.MulNumber(0);
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, MulMatrix_1) {
    S21Matrix josky(2, 3), flex(3, 2);
    double count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            flex(j, i) = count;
            count++;
        }
    }
    josky.MulMatrix(flex);
    S21Matrix res(2, 2);
    res(0, 0) = 14;
    res(0, 1) = 32;
    res(1, 0) = 32;
    res(1, 1) = 77;
    EXPECT_TRUE(josky.EqMatrix(res));
}

TEST(test, MulMatrix_2) {
    S21Matrix josky(2, 3), flex(4, 2);
    double count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            flex(j, i) = count;
            count++;
        }
    }
    EXPECT_THROW(josky.MulMatrix(flex), std::out_of_range);
}

TEST(test, Transpose_1) {
    S21Matrix josky(2, 3), flex(3, 2);
    double count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            flex(j, i) = count;
            count++;
        }
    }
    josky = josky.Transpose();
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, Transpose_2) {
    S21Matrix josky(2, 3), flex(3, 2);
    double count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            flex(j, i) = count;
            count++;
        }
    }
    flex = flex.Transpose();
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, CalcComplements_1) {
    S21Matrix josky(2, 2), flex(2, 2);
    int count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 2; j++) {
            josky(i, j) = count;
            count++;
        }
    }
    josky = josky.CalcComplements();
    flex(0, 0) = 4;
    flex(0, 1) = -3;
    flex(1, 0) = -2;
    flex(1, 1) = 1;
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, Determinant_1) {
    S21Matrix josky;
    int count = 1;
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            count++;
        }
    }
    EXPECT_DOUBLE_EQ(0, josky.Determinant());
}

TEST(test, Determinant_2) {
    S21Matrix josky;
    int count = 0;
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            josky(i, j) = count;
            count += i + j;
        }
        count *= 2;
    }
    EXPECT_DOUBLE_EQ(-12, josky.Determinant());
}

TEST(test, Inverse_1) {
    S21Matrix josky(2, 2), flex(2, 2);
    int count = 1;
    for (auto i = 0; i < 2; i++) {
        for (auto j = 0; j < 2; j++) {
            josky(i, j) = count;
            count++;
        }
    }
    josky = josky.InverseMatrix();
    flex(0, 0) = -2;
    flex(0, 1) = 1;
    flex(1, 0) = 1.5;
    flex(1, 1) = -0.5;
    EXPECT_TRUE(josky.EqMatrix(flex));
}

TEST(test, Inverse_2) {
    S21Matrix josky(2, 2), flex(2, 2);
    josky(0, 0) = 1;
    josky(0, 1) = 1;
    josky(1, 0) = 3;
    josky(1, 1) = 2;
    josky = josky.InverseMatrix();
    flex(0, 0) = -2;
    flex(0, 1) = 1;
    flex(1, 0) = 3;
    flex(1, 1) = -1;
    EXPECT_TRUE(josky.EqMatrix(flex));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}