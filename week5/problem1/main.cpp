#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

#include "matrix.hpp"
#include "square_matrix.hpp"

int main() {
  SquareMatrix U1;
  SquareMatrix U2(3);
  vector<double> UB{6, 2, 9, 0, 5, 2.5, 0, 0, -19.0 / 6};
  SquareMatrix U(3, UB);
  cout << U.gauss_elim() << endl;
  cout << U.det() << endl;
  // -95
  vector<double> VB = {9, 3, 4, 4, 3, 4, 1, 1, 1};
  SquareMatrix V(3, VB);
  cout << V.gauss_elim() << endl;
  cout << V.det() << endl;
  // -5

  SquareMatrix V3 = V.power(3);
  cout << V3 << endl;
}
