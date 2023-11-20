#include<iostream>
#include<stdexcept>

class Fraction {
    int _nom;
    int _denom;
public:
    int get_nom() const {
        return _nom;
    } // Returns numerator

    int get_denom() const {
        return _denom;
    } // Returns denominator

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
    void reduce() {
        int common = gcd(_nom, _denom);
        _nom /= common;
        _denom /= common;
    } // divide num and denom by their gcd
    // Define Ctor to initializes the fraction
    // `Fraction(x, y)` >> fraction x/y.
    Fraction(int x, int y) : _nom(x), _denom(y) {
        if (_denom == 0) {
            throw std::logic_error("Denominator cannot be zero.");
        }
        reduce();
    }
    
    // `Fraction(x)` >> fraction x/1.
    Fraction(int x) : _nom(x), _denom(1) {}
    // `Fraction()` >> fraction 0/1.
    Fraction() : _nom(0), _denom(1) {}
    // `Fraction(x, 0)` >> throw logic_error.
    // What else?
    // Do need to define other special functions?
    ~Fraction() = default;

    void print() const {
        std::cout << _nom << "/" << _denom << std::endl;
    } // prints fraction to screen, format a/b
    Fraction reciprocal() const {
        return Fraction(_denom, _nom);
    } // F.reciprocal returns reciprocal of F
    Fraction add(const Fraction &G) const {
        int new_nom = _nom * G._denom + G._nom * _denom;
        int new_denom = _denom * G._denom;
        return Fraction(new_nom, new_denom);
    } // F.add(G) returns F+G
    Fraction mult(const Fraction &G) const {
        int new_nom = _nom * G._nom;
        int new_denom = _denom * G._denom;
        return Fraction(new_nom, new_denom);
    }; // F.mult(G) returns FG

};