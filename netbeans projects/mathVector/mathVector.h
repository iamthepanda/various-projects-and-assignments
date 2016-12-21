/* 
 * File:   mathVector.h
 * Author: George
 *
 * Created on March 3, 2015, 12:01 PM
 * 
 * which will be instantiated into objects of math vectors
 */

/*#ifndef MATHVECTOR_H
#define	MATHVECTOR_H



#endif	// MATHVECTOR_H

 */

#include <iostream>
const int MAXSIZE = 1000;

enum class vectorType {row, col};

//using namespace std;

class mathVector {
public:
    //constructors
    mathVector();   //default constructor 0-->size
    explicit mathVector(int mv_size);    //mv_size-->size, set all elements

    //accessors (i.e. getters)
    int get_size() const; //return the size of the mathVector
    vectorType get_type() const;  //return the type of the vector
    
    //mutators (i.e. setters)
    void set_size(int newSize); //change the size to newSize
    mathVector add(const mathVector& rhs    ) const;  //add two m-vector
    mathVector operator+(const mathVector& rhs    ) const;  //

private:
    double mv[MAXSIZE];
    int size;
    vectorType type;    //row vector or column vector
};