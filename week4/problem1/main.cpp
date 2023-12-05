#include<iostream>
#include<list>
#include<vector>
using namespace std;

template<class T1, class T2> class Pair {
    T1 _left;
    T2 _right;
public:
    Pair(const T1 &a, const T2 &b);

    // getters
    inline T1 left() const;
    inline T2 right() const;

    // setters
    inline void left(const T1 &a);
    inline void right(const T2 &b);

    // Overload assignment operator
    inline Pair &operator=(const Pair &rhs);

    // Overload equality operator
    inline bool operator==(const Pair &rhs) const;
};

// Constructor
template<class T1, class T2>
Pair<T1, T2>::Pair(const T1 &a, const T2 &b) : _left(a), _right(b) {}

// Getters
template<class T1, class T2> inline T1 Pair<T1, T2>::left() const {
    return _left;
}

template<class T1, class T2> inline T2 Pair<T1, T2>::right() const {
    return _right;
}

// Setters
template<class T1, class T2> inline void Pair<T1, T2>::left(const T1 &a) {
    _left = a;
}

template<class T1, class T2> inline void Pair<T1, T2>::right(const T2 &b) {
    _right = b;
}

// Overload equality operator
template<class T1, class T2>
inline Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair<T1, T2> &rhs) {
    if (this != &rhs) {
        _left = rhs.left;
        _right = rhs.right;
    }
    return *this;
}

// Overload equality operator
template<class T1, class T2>
inline bool Pair<T1, T2>::operator==(const Pair<T1, T2> &rhs) const {
    return (_left == rhs._left) && (_right == rhs._right);
}

int main() {
    Pair<double, string> P(2.718, "test");
    cout << P.left() << endl;
    cout << P.right() << endl;

    vector<int> v;
    list<double> L;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        L.push_back(i * 3.1415);
    }

    Pair<vector<int>, list<double>> P2(v, L);
    cout << P2.left().size() << endl;
    cout << P2.right().size() << endl;

    // Test overloaded operators
    Pair<int, int> pp(2, 3);
    auto p2 = pp;
    cout << (p2 == pp) << endl;

    p2.left(3);
    cout << (p2 == pp) << endl;

    return 0;
}
