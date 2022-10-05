#ifndef __S21_MATRIX_OOP_H__
#define __S21_MATRIX_OOP_H__

#include <iostream>
#include <cmath>

class S21Matrix {
private:
    // attributes
    int rows_, cols_;                                           // rows and columns attributes
    double **matrix_;                                                // pointer to the memory where the matrix will be allocated

public:
    S21Matrix();                                                // default constructor
    S21Matrix(int rows, int cols);                              // parameterized constructor
    S21Matrix(const S21Matrix& o);                              // copy cnstructor
    S21Matrix(S21Matrix&& o);                                   // move cnstructor
    ~S21Matrix();                                               // destructor

    // some operators overloads
    bool operator==(const S21Matrix& other) const;
    S21Matrix& operator=(S21Matrix&& other) noexcept;
    S21Matrix& operator=(const S21Matrix& other);                   // assignment operator overload
    double& operator()(int row, int col);                          // index operator overload
    const double& operator()(int row, int col) const;
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix operator+(const S21Matrix& other) const;
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other) const;
    S21Matrix operator*(const S21Matrix& other);
//    S21Matrix operator*(double num);
    friend S21Matrix operator*(S21Matrix&, double);
    friend S21Matrix operator*(double, S21Matrix&);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(double num);

    // some public methods
    bool EqMatrix(const S21Matrix& other) const;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(double num);
    void MulMatrix(const S21Matrix& other);
    double Determinant();
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();
    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;
    void setRows(int row);
    void setCols(int col);

    // support
    static S21Matrix s21_delete(int row, int col, S21Matrix& A);
    void create_m(S21Matrix&) const;
    void delete_m(S21Matrix&) const;
};

S21Matrix operator*(double, S21Matrix&);
S21Matrix operator*(S21Matrix&, double);

#endif
