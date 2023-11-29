#include<iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account();
};

class Checking: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::checking" << std::endl;
    }   
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::savings" << std::endl;
    }   
};

class Trust: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::trust" << std::endl;
    }   
};

int main() {
    std::cout << "\n === Points ===" << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    std::cout << "\n === Clean up ===" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}