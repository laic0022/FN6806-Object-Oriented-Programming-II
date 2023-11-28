#include<iostream>
#include"Savings_Account.hpp"

Savings_Account::Savings_Account() {}
Savings_Account::~Savings_Account() {}

void Savings_Account::deposit(double amount) {
    std::cout << "Saving Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Saving Account withdraw called with " << amount << std::endl;
}