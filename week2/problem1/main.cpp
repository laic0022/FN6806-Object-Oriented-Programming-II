#include<iostream>
#include"fraction.hpp"

using namespace std;

int main() {
    Fraction x1(2, 4);
    x1.print();

    cout << "x1 + x1: ";
    x1.add(x1).print();
    cout << "x1 * x1: ";
    x1.mult(x1).print();

    return 0;
}

