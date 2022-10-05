#include "s21_matrix_oop.h"

void S21Matrix::create_m(S21Matrix& m) const {
    m.matrix_ = new double*[rows_]{};
    for (int i = 0; i < m.rows_; i++)
        m.matrix_[i] = new double [m.cols_]{};
}

void S21Matrix::delete_m(S21Matrix& m) const {
    for (int i = 0; i < m.rows_; i++) {
        delete [] m.matrix_[i];
    }
    delete [] m.matrix_;
}

// Конструкторы
S21Matrix::S21Matrix() {
    rows_ = 3;
    cols_ = 3;
    create_m(*this);
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows < 1 || cols < 1)
        throw std::out_of_range("Incorrect input, index is out of range");
    create_m(*this);
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
    create_m(*this);
    for (int i = 0; i < other.rows_; i++)
        for (int j = 0; j < other.cols_; j++)
            matrix_[i][j] = other.matrix_[i][j];
    cols_ = other.cols_;
    rows_ = other.rows_;
}

// Конструктор перемещения
S21Matrix::S21Matrix(S21Matrix&& other) {
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
}

// Деструктор
S21Matrix::~S21Matrix() {
    if (matrix_) {
        delete_m(*this);
    }
}

// Оператор присваивания перемещением
S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
    if (this != &other) {
        if (matrix_) {
            delete_m(*this);
        }
        rows_ = other.rows_;
        cols_ = other.cols_;
        create_m(*this);
        for (int i = 0; i < rows_; i++)
            for (int j = 0; j < cols_; j++)
                matrix_[i][j] = other.matrix_[i][j];
        other.matrix_ = nullptr;
        other.rows_ = 0;
        other.cols_ = 0;
    }
    return *this;
}

// Оператор присваивания копированием
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (this == &other)
        return *this;
    if (matrix_) {
        delete_m(*this);
    }
    cols_ = other.cols_;
    rows_ = other.rows_;
    create_m(*this);
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] = other.matrix_[i][j];
    return *this;
}

// Обращение к элементам матрицы
double& S21Matrix::operator()(int row, int col) {
    if (row >= rows_ || col >= cols_)
        throw std::out_of_range("Incorrect input, index is out of range");
    return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
    if (row >= rows_ || col >= cols_)
        throw std::out_of_range("Incorrect input, index is out of range");
    return matrix_[row][col];
}

// operator overload example
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
    S21Matrix m = *this;
    m.SumMatrix(other);
    return m;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    this->SumMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
    S21Matrix m = *this;
    m.SubMatrix(other);
    return m;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    this->SubMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix m = *this;
    m.MulMatrix(other);
    return m;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    this->MulMatrix(other);
    return *this;
}

S21Matrix operator*(double num, S21Matrix& other) {
    S21Matrix m = other;
    m.MulNumber(num);
    return m;
}

S21Matrix operator*(S21Matrix& other, double num) {
    S21Matrix m = other;
    m.MulNumber(num);
    return m;
}

S21Matrix& S21Matrix::operator*=(const double num) {
    this->MulNumber(num);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
    return this->EqMatrix(other);
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::out_of_range(
                "Incorrect input, matrices should have the same size");
    }
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::out_of_range(
                "Incorrect input, matrices should have the same size");
    }
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (cols_ != other.rows_)
        throw std::out_of_range("Different rows and colums");
    S21Matrix result {rows_, other.cols_};
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < other.cols_; j++)
            for (int k = 0; k < cols_; k++)
                result(i, j) += matrix_[i][k] * other.matrix_[k][j];
    *this = result;
}

S21Matrix S21Matrix::s21_delete(int row, int col, S21Matrix& A) {
    int n = 0, m = 0;
    S21Matrix result{A.rows_ - 1, A.cols_ - 1};
    for (auto i = 0; i < A.rows_; i++) {
        for (auto j = 0; j < A.cols_; j++) {
            if (i != row && j != col) {
                result(n, m) = A.matrix_[i][j];
                m++;
                if (m == A.cols_ - 1) {
                    n++;
                    m = 0;
                }
            }
        }
    }
    return result;
}

double S21Matrix::Determinant() {
    if (cols_ != rows_)
        throw std::out_of_range("cols != rows");
    double result = 0;
    if (cols_ == 2) {
        result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else if (cols_ == 1) {
        result = matrix_[0][0];
    } else {
        S21Matrix del;
        double res = 0;
        for (auto j = 0; j < cols_; j++) {
            del = s21_delete(0, j, *this);
            res = del.Determinant();
            result += pow(-1, j) * matrix_[0][j] * res;
        }
    }
    return result;
}

S21Matrix S21Matrix::Transpose() {
    S21Matrix result{cols_, rows_};
    for (auto i = 0; i < rows_; i++)
        for (auto j = 0; j < cols_; j++)
            result(j, i) = matrix_[i][j];
    return result;
}

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_)
        throw std::out_of_range("cols != rows");
    S21Matrix result{rows_, cols_}, del;
    double res = 0;
    for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < cols_; j++) {
            del = s21_delete(i, j, *this);
            res = del.Determinant();
            result(i, j) = pow(-1, i + j) * res;
        }
    }
    return result;
}

S21Matrix S21Matrix::InverseMatrix() {
    double opr = this->Determinant();
    if (fabs(opr) < 1e-6)
        throw std::out_of_range("Determinant = 0");
    if (rows_ < 2 || cols_ < 2)
        throw std::out_of_range("Incorrect matrix");
    S21Matrix result = this->CalcComplements().Transpose();
    result.MulNumber(1.0 / opr);
    return result;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        return false;
    for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < cols_; j++) {
            if (matrix_[i][j] != other.matrix_[i][j])
                return false;
        }
    }
    return true;
}

// Accessor для получения столбцов
int S21Matrix::getCols() const {
    return cols_;
}

// Accessor для получения строк
int S21Matrix::getRows() const {
    return rows_;
}

// Mutator для изменения количества столбцов
void S21Matrix::setCols(int col) {
    if (col < 1)
        throw std::out_of_range("Incorrect input, index is out of range");
    if (col <= cols_) {
        cols_ = col;
    } else {
        S21Matrix matr {rows_, col};
        for (int i = 0; i < rows_; i++)
            for (int j = 0; j < cols_; j++)
                matr.matrix_[i][j] = matrix_[i][j];
        *this = matr;
    }
}

// Mutator для изменения количества строк
void S21Matrix::setRows(int row) {
    if (row < 1)
        throw std::out_of_range("Incorrect input, index is out of range");
    if (row <= rows_) {
        rows_ = row;
    } else {
        S21Matrix matr{row, cols_};
        for (int i = 0; i < rows_; i++)
            for (int j = 0; j < cols_; j++)
                matr.matrix_[i][j] = matrix_[i][j];
        *this = matr;
    }
}
