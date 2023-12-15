//matrix.hpp
#include<iostream>
#include<iomanip>
#include<numeric>
#include<vector>
using namespace std;

class Matrix {
    int n;
    int m;
    vector<double> entries;
public:
    Matrix(int n , int m, const vector<double> &entries) : n(n), m(m), entries(entries) {}
    Matrix() : n(0), m(0), entries({}) {}
    Matrix(int n, int m) : n(n), m(m), entries(n * m, 0) {}
    Matrix(int n, int m, double val) : n(n), m(m), entries(n * m, val) {}
    
    Matrix(const Matrix &B);

    Matrix &operator=(const Matrix &B);

    ~Matrix();

    int rows() const;
    int columns() const;
    double get_entry(int i, int j) const;
    void set_entry(int, int j, int x);
    void print() const;

    Matrix operator+(const Matrix &B) const;
    Matrix operator-(const Matrix &B) const;
    Matrix operator*(const Matrix &B) const;
};