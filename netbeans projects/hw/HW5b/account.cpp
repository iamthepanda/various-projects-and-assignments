/* 
 * File:   account.cpp
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:35 AM
 */
#include "account.h"
#include <string>

using namespace std;

double Account::deposit(double amount)throw(Exception_Negative_Deposit) {
    Exception_Negative_Deposit negDep;
    
    if (amount > 0)
        balance += amount;
    else
        throw negDep; // code indicating error
    
    return balance;
}
// returns new balance or -1 if invalid amount

double Account::withdraw(double amount)throw(Exception_Overdraw, Exception_Negative_Withdraw){
    Exception_Overdraw over;
    Exception_Negative_Withdraw negWith;
    
    if (amount > balance)
        throw over;
    else if (amount < 0)
        throw negWith;
    else
        balance -= amount;
    
    return balance;
}