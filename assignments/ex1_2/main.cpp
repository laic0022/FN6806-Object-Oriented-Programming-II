#include"quadratic.hpp"
#include<cmath>
#include<iostream>

using namespace std;

QuadraticEquation::QuadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};

void QuadraticEquation::solve() const {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < -1e10) {
        cout << "No real solutions." << endl;
    } else if (discriminant > 1e-10){
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;

    } else {
        double x = -b / (2 * a);
        cout << "x = " << x << endl;
    }
}

int main() {
    QuadraticEquation equation1(1.0, -2.0, 1.0);

    equation1.solve();
    return 0;
}