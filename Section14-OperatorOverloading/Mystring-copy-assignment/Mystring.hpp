#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char *str;
public:

    // No-args constructor
    Mystring();

    // Overloaded constructor
    Mystring(const char *s);

    // Copy constructor
    Mystring(const Mystring &source);

    // Destructor
    ~Mystring();

    // Copy assignment
    Mystring &operator=(const Mystring &rhs);

    void display() const;

    int get_length() const;
    const char *get_str() const;
};


#endif
