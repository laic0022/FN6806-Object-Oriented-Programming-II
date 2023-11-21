//matrix.hpp
#include<iomanip>
#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

class Matrix {
    int n;
    int m;
    vector<double> entries;
public:
    Matrix(int n, int m, const vector<double> &entries) : n(n), m(m), entries(entries) {}
    Matrix() : n(0), m(0), entries({}) {}
    Matrix(int n, int m) : n(n), m(m), entries(n * m, 0) {}
    Matrix(int n, int m, double val) : n(n), m(n), entries(n* m, val) {}

    // copy constructor
    Matrix(const Matrix &B);

    //assignment operator
    Matrix &operator=(const Matrix &B);

    ~Matrix();

    int rows() const;
    int columns() const;
    double get_entry(int i, int j) const;
    void set_entry(int i, int j, double x);
    void print () const;

    Matrix operator+(const Matrix &B) const;
    Matrix operator-(const Matrix &B) const;
    Matrix operator*(const Matrix &B) const;
    
};