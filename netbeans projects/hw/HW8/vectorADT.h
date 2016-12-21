/* 
 * File:        vectorADT.h
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 *
 * Created on May 1, 2015, 5:06 PM
 */

#ifndef VECTORADT_H
#define	VECTORADT_H

#include <iostream>

//A Vector stores a list of elements:

class Vector_double {
private:
    int capacity;
    int size;
    double* ptr;

public:
    Vector_double(); //default constructor

    //big 3
    Vector_double(const Vector_double& that); // 1. copy constructor
    void operator=(const Vector_double& that); // 2. copy assignment operator
    ~Vector_double(); // 3. destructor
    
    int getCapacity();  //Returns the number of elements that the vector could store without allocating more storage.
    bool isEmpty(); //the "empty" function: Tests if the vector container is empty.
    void erase(int first, int last);    //Removes element or range of elements in a vector from the specified positions.
    void insert(int first, double r);   //Inserts element or number of elements into the vector at a specified position.
    void pop_back();    //the "pop_back" function: Deletes the element at the end of the vector.
    void push_back(double r);   //the "push_back" function": Adds an element to the end of the vector.
    void resize(int size);  //Specifies a new size for a vector. The new size can be smaller or larger than the old size.
    void shrink_to_fit();   //the "shrink_to_fit" function: Discards excess capacity.
    int getSize();  //the "size" function" Returns the number of elements stored in the vector.
    friend std::ostream& operator<<(std::ostream& out, const Vector_double& that);  //print out the elements in a vector.
};

#endif	/* VECTORADT_H */