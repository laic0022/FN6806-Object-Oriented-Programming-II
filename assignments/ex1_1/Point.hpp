#include<iostream>
using namespace std;

class Point {
public:
    int x;

    // Default constructor
    Point() : x(0) {
        cout << "Default constructor called" << endl;
    }

    // Non-Default constructor
    Point(int x) : x(x) {
        cout << "Non default constructor called" << endl;
    }

    // Copy constructor
    Point(const Point &other) : x(other.x) {
        cout << "Copy constructor called" << endl;
    }

    // Assignment operator (with reference)
    Point &operator=(const Point &other) {
        x = other.x;
        cout << "Assignment operator called" << endl;
        return *this;
    }
};