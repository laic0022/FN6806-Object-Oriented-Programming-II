 #include <iostream>

using namespace std;

class Base {
    int value;
public:
    Base() : value(0) {
        cout << "Base no-args constructor" << endl;
    }

    Base(int x) : value(x) {
        cout << "Base (int) overloaded constructor" << endl;
    }
    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    using Base::Base;
    int double_value;
public:
    Derived() : double_value(0) {
        cout << "Derived no-args constructor" << endl;
    }

    Derived(int x) : double_value(x * 2) {
        cout << "Derived (int) overloaded constructor" << endl;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base b;
    Base b1{100};
    Derived d;
    Derived d1{1000};
    return 0;
}