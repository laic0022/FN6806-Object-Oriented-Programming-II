// linearsystem.hpp
#include<vector>

class LinearSystem {
    // (i, j) entry of matrix is A[3(i-1)+j-1]
    std::vector<double> A;
    std::vector<double> b;
    mutable std::vector<double> sol;
public:
    LinearSystem(const std::vector<double> &A, const std::vector<double> &b) : A(A), b(b) {}
    
    void solve() const;
    void print() const;
};