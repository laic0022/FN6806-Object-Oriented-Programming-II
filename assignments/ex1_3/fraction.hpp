//fraction.hpp
#include<stdexcept>
#include<iostream>

class Fraction {
    int _nom;
    int _denom;
public:
    Fraction(int x, int y) : _nom(x), _denom(y) {
        if (_denom == 0) {
            throw std::logic_error("Denominator cannot be zero.");
        }
        reduce();
    }

    Fraction(int x) : _nom(x), _denom(1) {}
    Fraction() : _nom(0), _denom(1) {}

    // Destructor
    ~Fraction() = default;

    // Getter functions
    int get_nom() const {
        return _nom;
    }

    int get_denom() const {
        return _denom;
    }

    // Other member functions
    void print() const {
        std::cout << _nom << " / " << _denom << std::endl; 
    }

    void reduce() {
        int common = gcd(_nom, _denom);
        _nom /= common;
        _denom /= common;
    }

    // Function for computing gcd
    int gcd(int u, int v) {
        if (u < 0) u = -u;
        if (v < 0) v = -v;
        int r;
        while (v != 0) {
            r = u % v;
            u = v;
            v = r;
        }
        return u;
    }

    Fraction reciprocal() const {
        return Fraction(_denom, _nom);
    }

    Fraction add(const Fraction &G) const {
        int new_nom = _nom * G._denom + G._nom * _denom;
        int new_demon = _denom * G._denom;
        return Fraction(new_nom, new_demon);
    }

    Fraction mult(const Fraction &G) const {
        int new_nom = _nom * G._nom;
        int new_demon = _denom * G._denom;
        return Fraction(new_nom, new_demon);
    }

};