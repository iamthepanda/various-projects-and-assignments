/* 
 * File:   account.h
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:36 AM
 */
#include "account-exception.h"
#include <string>

#ifndef ACCOUNT_H
#define	ACCOUNT_H

class Account {
private:
    double balance; //balance can't be accessed directly
public:

    inline Account() : balance(0) { //initialize balance to 0 with inline function
    }

    inline Account(double initialDeposit) : balance(initialDeposit) { //set balance to initialDeposit
    }

    inline double getBalance() {
        return balance;
    }

    //functions will handle deposit and withdraw operations
    double deposit(double amount)throw (Exception_Negative_Deposit);
    double withdraw(double amount)throw (Exception_Overdraw, Exception_Negative_Withdraw);
};

#endif	/* ACCOUNT_H */