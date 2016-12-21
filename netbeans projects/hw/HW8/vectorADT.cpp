/* 
 * File:        vectorADT.cpp
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

Vector_double::Vector_double() : capacity(0), size(0), ptr(NULL) {
}

//big 3
//1. copy constructor

Vector_double::Vector_double(const Vector_double& that) : capacity(that.capacity), size(that.size) {
    for (int i = 0; i < size; i++)
        ptr[i] = that.ptr[i];
}

//2. copy assignment operator

void Vector_double::operator=(const Vector_double& that) {
    capacity = that.capacity;
    size = that.size;

    for (int i = 0; i < size; i++)
        ptr[i] = that.ptr[i];
}

//3. destructor

Vector_double::~Vector_double() {
    if (ptr != NULL) {
        delete[]ptr;
        ptr = NULL;
        size = 0;
        capacity = 0;
    }
}

//the "capacity" function: Returns the number of elements that the vector could store without allocating more storage.

int Vector_double::getCapacity() {
    return capacity;
}

//the "empty" function: Tests if the vector container is empty.

bool Vector_double::isEmpty() {
    if (size == 0) {
        
        cout << "the vector is empty\n\n";
        return true;
    } else {
        
        cout << "the vector is not empty\n\n";
        return false;
    }
}

//the "erase" function: Removes an element or a range of elements in a vector from the specified positions.

void Vector_double::erase(int first, int last) {
    double *temp = new double[capacity];

    if (first == last) { //if range is only one element
        //set elements of temp[] to ptr[]
        for (int i = 0; i < first; i++)
            temp[i] = ptr[i];
        for (int i = first; i < size - 1; i++)
            temp[i] = ptr[i + 1];

        delete [] ptr;
        ptr = temp;
        size--;
    } else { //handle range with multiple elements
        //set elements of temp[] to ptr[]
        for (int i = 0; i < first; i++)
            temp[i] = ptr[i];
        for (int i = first; i < size - last + first; i++)
            temp[i] = ptr[i + last - first];

        delete []ptr;
        ptr = temp;
        size = size - last + first;
    }
}

//the "insert" function: Inserts an element or a number of elements into the vector at a specified position.

void Vector_double::insert(int first, double r) {
    double *temp;

    if (capacity > size)
        temp = new double[capacity];
    else {
        temp = new double[capacity + 1];
        capacity++;
    }

    for (int i = 0; i < first; i++) //first set elements of temp[] to ptr[]
        temp[i] = ptr[i];

    temp[first] = r;

    for (int i = first; i < size; i++) //second set elements of temp[] to ptr[]
        temp[i + 1] = ptr[i];

    delete [] ptr;
    ptr = temp;
    size++;
}

//the "pop_back" function: Deletes the element at the end of the vector.

void Vector_double::pop_back() {
    if (size > 0)
        size--;
    else
        size = 0;
}

//the "push_back" function": Adds an element to the end of the vector.

void Vector_double::push_back(double r) {
    if (capacity == 0) {
        ptr = new double[1];
        ptr[0] = r;
        size++;
        capacity++;
    } else if (capacity > size) { //increase the size by one and add one more value to ptr[] if there is enough capacity
        ptr[size] = r;
        size++;
    } else {
        double *temp = NULL;

        try {
            temp = new double[capacity + 1];
        } catch (bad_alloc& e) {
            cerr << "Vector_double push_back: " << e.what();
        }

        for (int i = 0; i < size; i++)
            temp[i] = ptr[i];

        temp[size] = r;
        delete [] ptr;
        ptr = temp;
        size++;
        capacity++;
    }
}

//the "resize" function: Specifies a new size for a vector. The new size can be smaller or larger than the old size.

void Vector_double::resize(int newSize) {
    if (newSize <= size)
        size = newSize;
    else {
        double *temp = new double[newSize];

        for (int i = 0; i < size; i++)
            temp[i] = ptr[i]; //set elements of temp[] to ptr[]
        for (int i = size; i < newSize; i++) //set elements to 0
            temp[i] = 0;

        delete [] ptr;
        ptr = temp;
        capacity = newSize;
    }
}

//the "shrink_to_fit" function: Discards excess capacity.

void Vector_double::shrink_to_fit() {
    if (capacity > size) {
        double *temp = new double[size];

        for (int i = 0; i < size; i++)
            temp[i] = ptr[i];

        delete [] ptr;
        ptr = temp;
        capacity = size;
    }
}

//the "size" function" Returns the number of elements stored in the vector.

int Vector_double::getSize() {
    return size;
}

//the overloaded output operator (<<) to print out the elements in a vector. 

ostream& operator<<(ostream& out, const Vector_double& that) {
    for (int i = 0; i < that.size; i++)
        out << that.ptr[i] << endl;

    return out;
}