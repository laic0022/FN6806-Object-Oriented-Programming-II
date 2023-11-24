#include<iostream>
#include<vector>
#include"Mystring.hpp"

using namespace std;

int main() {
    Mystring a {"Hello"};
    Mystring b;
    b = a;
    b = "This is a test";

    return 0;
}