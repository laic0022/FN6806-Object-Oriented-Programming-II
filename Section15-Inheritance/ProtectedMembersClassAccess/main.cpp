#include<iostream>

using namespace std;

class Base {
public:
    int a {0};
    void display() {
        cout << a << " , " << b << " , " << c << endl;
    }
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base {
public:
    void access_base_members() {
        a = 100;
        b = 200;
    }
};

int main() {

    cout << "===Base member access from base objects==============" << endl;
    Base base;
    base.a = 100;
    // base.b = 200;
    // base.c = 300;

    cout << "===Base member access from derived objects===========" << endl;
    Derived d;
    d.a = 100;
    // d.b = 200;
    // d.c = 300;

    return 0;
}