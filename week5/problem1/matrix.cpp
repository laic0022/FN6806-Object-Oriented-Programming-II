#include "matrix.hpp"
#include <cmath>
using namespace std;

Matrix Matrix::operator+(const Matrix &B) const {
  if (n != B.rows() || m != B.columns()) {
    throw logic_error("cannot add matrices");
  }

  Matrix Result(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      Result.set_entry(i, j, get_entry(i, j) + B.get_entry(i, j));
  return Result;
}

Matrix Matrix::operator-(const Matrix &B) const {
  if (n != B.rows() || m != B.columns()) {
    throw logic_error("cannot add matrices");
  }

  Matrix Result(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      Result.set_entry(i, j, get_entry(i, j) - B.get_entry(i, j));
  return Result;
}

Matrix Matrix::operator*(const Matrix &B) const {
  if (m != B.rows()) {
    throw logic_error("cannot multiply matrices");
  }
  Matrix Result(n, B.columns());
  double sum;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= B.columns(); j++) {
      sum = 0;
      for (int k = 1; k <= m; k++)
        sum += get_entry(i, k) * B.get_entry(k, j);
      Result.set_entry(i, j, sum);
    }
  return Result;
}

int Matrix::rows() const { return n; }

int Matrix::columns() const { return m; }

double Matrix::get_entry(int i, int j) const {
  return entries[(i - 1) * m + j - 1];
}

void Matrix::set_entry(int i, int j, double x) {
  entries[(i - 1) * m + j - 1] = x;
}

void Matrix::print() const {
  for (size_t i = 1; i <= (size_t)n; i++) {
    for (size_t j = 1; j <= (size_t)m; j++)
      cout << setw(13) << entries[(i - 1) * m + j - 1];
    cout << endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
  for (size_t i = 1; i <= (size_t)m.n; i++) {
    for (size_t j = 1; j <= (size_t)m.m; j++)
      os << setw(13) << m.entries[(i - 1) * m.m + j - 1];
    os << endl;
  }
  return os;
}

void Matrix::row_add(int i, int j, double z) {
  for (int k = 1; k <= m; k++)
    set_entry(j, k, get_entry(j, k) + z * get_entry(i, k));
}

void Matrix::swap_rows(int i, int j) {
  if (i < 0 || i > n || j < 0 || j > m) {
    throw logic_error("Matrix::swap_rows: indices out of range");
  }

  double buffer;
  for (int k = 1; k <= m; k++) {
    buffer = get_entry(j, k);
    set_entry(j, k, get_entry(i, k));
    set_entry(i, k, buffer);
  }
}

Matrix Matrix::gauss_elim() const {
  Matrix result(*this);

  for (int i = 1; i <= min(result.rows(), result.columns()); i++) {
    // Find the pivot row
    int pivot_row = i;
    for (int j = i + 1; j <= result.rows(); j++) {
      if (abs(result.get_entry(j, i)) > abs(result.get_entry(pivot_row, i))) {
        pivot_row = j;
      }
    }

    // Swap rows if needed
    if (pivot_row != i) {
      result.swap_rows(i, pivot_row);
    }

    // Perform Gaussian elimination
    for (int j = i + 1; j <= result.rows(); j++) {
      double factor = result.get_entry(j, i) / result.get_entry(i, i);
      result.row_add(i, j, -factor);
    }
  }

  return result;
};