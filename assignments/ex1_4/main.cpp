#include"linearsystem.hpp"
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<double> A = {1, 1, 1, 2, 3, 2, 3, -1, -1};
    vector<double> b = {6, 14, -2};
    LinearSystem ls(A, b);

    ls.solve();
    ls.print();
    
    return 0;
}