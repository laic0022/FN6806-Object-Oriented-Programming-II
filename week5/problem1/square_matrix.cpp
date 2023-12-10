#include "square_matrix.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

SquareMatrix::SquareMatrix() {
  cout << "SquareMatrix default constructor" << endl;
  // no need to do anything;
  // default constructor of Matrix will automatically be called
}

SquareMatrix::SquareMatrix(int n1) : Matrix(n1, n1) {
  cout << "SquareMatrix constructor1" << endl;
}

SquareMatrix::SquareMatrix(int n1, const vector<double> &A)
    : Matrix(n1, n1, A) {
  cout << "SquareMatrix constructor2" << endl;
}

SquareMatrix::SquareMatrix(const SquareMatrix &B) : Matrix(B) {
  cout << "SquareMatrix copy constructor" << endl;
}

SquareMatrix::SquareMatrix(const Matrix &B) : Matrix(B) {
  cout << "Matrix to SquareMatrix constructor" << endl;
}

SquareMatrix SquareMatrix::power(int t) const {
  SquareMatrix result(*this);
  for (int i = 1; i < t; i++) {
    result = result * (*this);
  }
  return result;
}

double SquareMatrix::det() const {
  // Implement the determinant calculation using Gaussian elimination
  // returns determinant of supporting object
  Matrix result = gauss_elim();
  double determinant = 1.0;

  for (int i = 1; i <= result.rows(); ++i) {
    determinant *= result.get_entry(i, i);
  }

  return determinant;
}