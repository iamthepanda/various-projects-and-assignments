/* 
 * File:   account-exception.h
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 9, 2015, 9:03 PM
 */
#include <exception>

#ifndef ACCOUNT_EXCEPTION_H
#define	ACCOUNT_EXCEPTION_H

//exception for case of trying to deposit with a negative number

class Exception_Negative_Deposit : public std::exception {
public:

    virtual const char* what() {
        return "Exception_Negative_Deposit";
    };
};

//exception for the case of trying to withdraw more than balance amount

class Exception_Overdraw : public std::exception {
public:

    virtual const char* what() {
        return "Exception_Overdraw";
    };
};

//exception for the case of trying to withdraw using a negative number

class Exception_Negative_Withdraw : public std::exception {
public:

    virtual const char* what() {
        return "Exception_Negative_Withdraw";
    };
};

#endif	/* ACCOUNT_EXCEPTION_H */