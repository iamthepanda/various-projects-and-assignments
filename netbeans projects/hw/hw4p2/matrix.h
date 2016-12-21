/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: declare the interface of the class Matrix
 *              which will be instantiated into objects of Matrices
 */
#ifndef Marix_h
#define Marix_h
#include <vector>
#include <iostream>

class Matrix {
private:
    std::vector< std::vector <float> > matrix;
    
public:
    //constructors
    Matrix();
    Matrix(const std::vector< std::vector <float> >& v);
    
    //accessors
    void blankMatrix(int a);
    float getNum(int row, int col) const;   //gets the values of row and col
    
    //mutators
    void setNum(int row, int col, int num);
    void transpose();
    
    //overload operators
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator*(float scalar) const;
    Matrix operator-(const Matrix& rhs) const; 
    friend std::ostream& operator<<(std::ostream& os, const Matrix& rhs);
};

#endif