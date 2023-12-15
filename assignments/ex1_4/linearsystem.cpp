#include"linearsystem.hpp"
#include<iostream>
#include<vector>

double determinant2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

double determinant3x3(const std::vector<double> &mat) {
    double det = 0;
    det += mat[0] * determinant2x2(mat[4], mat[5], mat[7], mat[8]);
    det -= mat[1] * determinant2x2(mat[3], mat[5], mat[6], mat[8]);
    det += mat[2] * determinant2x2(mat[3], mat[4], mat[6], mat[7]);
    return det;
}

void LinearSystem::print() const {
    if (!sol.empty()) {
        std::cout << "Solution: ";
        for (double x : sol) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No unique solution." << std::endl;
    }
}

void LinearSystem::solve() const {
    double detA = determinant3x3(A);
    if (std::abs(detA) > 1e-10) {
        sol.resize(3);

        for (int j = 0; j < 3; ++j) {
            std::vector<double> Aj = A;
            for (int i = 0; i < 3; ++i) {
                Aj[3 * i + j] = b[j];
            }
            sol[j] = determinant3x3(Aj) / detA;
        }
    } else {
        sol.clear();
    }
}