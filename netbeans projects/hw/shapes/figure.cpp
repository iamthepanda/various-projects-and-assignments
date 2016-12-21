/* 
 * File:        figure.cpp
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 * 
 * Created on May 15, 2015
 */

#include "figure.h"

void Figure::draw() {
    std::cout << "Figure::draw()\n";
}

void Figure::erase() {
    std::cout << "Figure::erase()\n";
}

void Figure::center() {
    draw();
    erase();
}