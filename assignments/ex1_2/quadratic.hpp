#include<iostream>

class QuadraticEquation {
    double a, b, c;
public:
    QuadraticEquation(double _a, double _b, double _c);
    void solve() const;
};