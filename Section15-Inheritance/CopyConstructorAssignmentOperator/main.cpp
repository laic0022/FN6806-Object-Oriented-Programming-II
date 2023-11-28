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

    Base(const Base &other) : value{other.value} {
        cout << "Base copy constructor" << endl;
    }

    Base &operator=(const Base &rhs) {
        cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    // using Base::Base;
    int double_value;
public:
    Derived() : Base{}, double_value(0) {
        cout << "Derived no-args constructor" << endl;
    }

    Derived(int x) : Base{x}, double_value(x * 2) {
        cout << "Derived (int) overloaded constructor" << endl;
    }

    Derived(const Derived &other) : Base(other), double_value{other.double_value} {
        cout << "Derived operator=" << endl;
    }

    Derived &operator=(const Derived &rhs) {
        cout << "Derived operator=" << endl;
        if (this == &rhs) {
            return *this;
        }
        Base::operator=(rhs);
        double_value = rhs.double_value;
        return *this;
    }
    
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    // Base b;
    // Base b1{100};
    // Derived d;
    Derived d{1000};
    Derived d1 {d};
    d = d1;

    return 0;
}