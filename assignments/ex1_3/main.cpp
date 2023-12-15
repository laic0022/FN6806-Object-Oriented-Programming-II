#include<iostream>
#include"fraction.hpp"

using namespace std;

int main() {
    Fraction x1(8, 4), x2(4, 8), x3(6);
    cout << "show x1 : ";
    x1.print();

    cout << "x1 + x2 = ";
    x1.add(x2).print();

    cout << "x1 * x2 = ";
    x1.mult(x2).print();

    return 0;
}