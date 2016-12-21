/* 
 * File:   exception-main.cpp
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:14 AM
 */
#include <string>
#include "exception.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() // Sample code to test the getProductID function
{
    int productIds[] = {4, 5, 8, 10, 13};
    string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};

    try {
        cout << getProductID(productIds, products, 5, "mouse") << endl;
        cout << getProductID(productIds, products, 5, "camera") << endl;
        cout << getProductID(productIds, products, 5, "laptop") << endl;    //this will be caught
    } catch (exceptionID ex) {  //whatever doesn't have a matching ID will be caught.
        cout << ex.what();  //ex throws the error specified in what
    }
    return 0;
}