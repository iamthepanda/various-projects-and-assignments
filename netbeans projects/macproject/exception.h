/* 
 * File:   exception.h
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:16 AM
 */
#include <string>
#include <exception>    //to use and create exceptions

#ifndef EXCEPTION_H
#define	EXCEPTION_H

//exceptionID returns a custom exception message

class exceptionID : public std::exception {
public:

    virtual const char* what() {
        return "Cannot find item.";
    };
};

int getProductID(int ids[], std::string names[], int numProducts, std::string target)throw (exceptionID); //getProductID has to be able to throw an exception of type exceptionID

#endif	/* EXCEPTION_H */