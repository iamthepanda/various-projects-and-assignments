/* 
 * File:   exception.cpp
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:14 AM
 */
#include "exception.h"
#include <string>

using namespace std;

int getProductID(int ids[], string names[], int numProducts, string target)throw (exceptionID) {
    exceptionID exc;    //create exception object

    //goes through matching ID's to products
    for (int i = 0; i < numProducts; i++) {
        if (names[i] == target)
            return ids[i];
    }

    throw exc; // not found
}