#include<iostream>
#include"Point.hpp"

using namespace std;

int main() {

    // call defalt constructor
    Point p1;
    cout << p1.x << endl;

    // call non-default constructor
    Point p2(43);
    cout << p2.x << endl;

    // call copy constructor
    Point p3(p1);
    cout << p3.x << endl;

    // assignment constructor
    p3 = p2;


    return 0;
}