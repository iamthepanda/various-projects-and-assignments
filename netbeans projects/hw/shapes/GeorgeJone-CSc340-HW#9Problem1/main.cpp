/* 
 * File:        main.cpp
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 * 
 * Created on May 15, 2015
 */

#include <iostream>

#include "figure.h"

#include "rectangle.h"

#include "triangle.h"

using std::cout;

int main()

{

  Triangle tri;

  tri.draw();  



  std::cout << "\nDerived class Triangle object calling" << " center().\n";

  tri.center();



  Rectangle rect;

  rect.draw();

  std::cout << "\nDerived class Rectangle object calling" << " center().\n";

  rect.center();

  return 0;

}