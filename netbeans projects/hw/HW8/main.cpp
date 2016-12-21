/* 
 * File:        main.cpp
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 * 
 * Created on May 1, 2015
 */

#include "vectorADT.h"
#include <iostream>

using namespace std;

int main() {
    Vector_double a;

    cout << "printing empty vector" << endl;
    //test assignment overload
    cout << a << endl;

    //test isEmpty()
    cout << "testing if vector is empty" << endl;
    a.isEmpty();

    //test push_back
    cout << "push_back" << endl;
    a.push_back(2);
    a.push_back(27);
    a.push_back(5);
    a.push_back(4);
    a.push_back(73);
    a.push_back(6);
    a.push_back(7);
    a.push_back(73);
    a.push_back(6);
    a.push_back(7);
    a.push_back(73);
    a.push_back(6);
    cout << a << endl;

    cout << "testing if vector is empty" << endl;
    a.isEmpty();

    //test erase() for index
    cout << "a.erase(0, 0)" << endl;
    a.erase(0, 0);
    cout << a << endl;

    //test erase for range
    cout << "a.erase(2,4)" << endl;
    a.erase(2, 4);
    cout << a << endl;

    //test insert() at position
    cout << "a.insert(1,16)" << endl;
    a.insert(1, 16);
    cout << a << endl;

    //test pop_back()
    cout << "a.pop_back()" << endl;
    a.pop_back();
    cout << a << endl;

    //test shrink_to_fit()
    cout << "before shrink_to_fit the capacity is " << a.getCapacity()
            << " and the size is " << a.getSize() << endl;
    a.shrink_to_fit();
    cout << "after shrink_to_fit the capacity is " << a.getCapacity()
            << " and the size is " << a.getSize() << endl;

    //test resize()
    a.resize(10);
    cout << "after a.resize(10);  the capacity is " << a.getCapacity()
            << " and the size is " << a.getSize() << endl;
    return 0;
}