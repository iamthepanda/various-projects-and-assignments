/* 
 * File:        triangle.h
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 * 
 * Created on May 15, 2015
 */

#ifndef _triangle
#define _triangle
#include "figure.h"
//#include <iostream>

//using namespace std;

class Triangle : public Figure {
public:
    void draw();
    void erase();
};

#endif