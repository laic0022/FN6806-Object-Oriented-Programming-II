#include<iostream>
#include<vector>
#include"matrix.hpp"
using namespace std;

int main() {
    Matrix A1(2, 2, {1, 2, 3, 4});
    Matrix A2(2, 2, {4, 3, 2, 1});

    cout << "A * B = " << endl;
    (A1 * A2).print();

    cout << "A + B = " << endl;
    (A1 + A2).print();

    cout << "A - B = " << endl;
    (A1 - A2).print();
    
    return 0;
}