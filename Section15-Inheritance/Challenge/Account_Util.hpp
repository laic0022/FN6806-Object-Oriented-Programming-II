#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include<vector>
#include"Account.hpp"
#include"Savings_Account.hpp"

void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &account, double amount);
void withdraw(std::vector<Account> &account, double amount);

void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &account, double amount);
void withdraw(std::vector<Savings_Account> &account, double amount);

#endif