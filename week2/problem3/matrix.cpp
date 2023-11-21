#include"matrix.hpp"

// copy constructor
Matrix::Matrix(const Matrix &B) : n(B.n), m(B.m), entries(B.entries) {}

// assignment operator

Matrix &Matrix::operator=(const Matrix &B) {
    if (this != &B) {
        n = B.n;
        m = B.m;
        entries = B.entries;
    }
    return *this;
}

// Destructor
Matrix::~Matrix() {}

int Matrix::rows() const {
    return n;
}

int Matrix::columns() const {
    return m;
}

double Matrix::get_entry(int i, int j) const {
    return entries[(i - 1) * m + (j - 1)];
}

void Matrix::set_entry(int i, int j, double x) {
    entries[(i - 1) * m + (j - 1)] = x;
}

void Matrix::print() const {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << setw(8) << get_entry(i, j) << " ";
        }
        std::cout << endl;
    }
}

// Matrix addition
Matrix Matrix::operator+(const Matrix &B) const {
    if (n != B.n || m != B.m) {
        throw std::logic_error("Matrix dimensions do not match for addition.");
    }

    Matrix result(n, m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result.set_entry(i, j, get_entry(i, j) + B.get_entry(i, j));
        }
    }

    return result;
}

// Matirx subtraction
Matrix Matrix::operator-(const Matrix &B) const {
    if (n != B.n || m != B.m) {
        throw std::logic_error("Matrix dimensions do not match for substraction.");
    }

    Matrix result(n, m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result.set_entry(i, j, get_entry(i, j) - B.get_entry(i, j));
        }
    }

    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &B) const {
    if (n != B.n || m != B.m) {
        throw std::logic_error("Matrix dimensions do not match for substraction.");
    }

    Matrix result(n, m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            double sum = 0.0;
            for (int k = 1; k <= m; ++k) {
                sum += get_entry(i, k) * B.get_entry(k, j);
            }
            result.set_entry(i, j, sum);
        }
    }
    return result;
}