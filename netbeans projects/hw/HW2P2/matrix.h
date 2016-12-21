#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>

class mcalc {
private:
    std::vector<std::vector<int> > nmatrix;
    std::vector<std::vector<int> > mmatrix;

public:
    friend std::ostream& operator<<(std::ostream& out, mcalc obj);
    int n;
    //std::vector< std::vector<int> > nmatrix(n, std::vector<int>(n)); //this is the 2D Vector that SHOULD HAVE worked but did not
    // so i made a bunch of int arrays instead
    //int nmatrix[100][100]; // Array for first matrix
    //int mmatrix[100][100]; // Array for second matrix
    int product[100][100]; // Array for Matrix for product
    int sum[100][100]; // Array for Matrix for Sum NOT USED
    int difference[100][100]; // Array for Matrix for negation

    mcalc();
    mcalc(std::vector<std::vector<int> > somevector);
    void resize(int i, int j);
    void getN(int matSize); // function to get N for NxN dimension for Matrix
    void getN2(int matSize);
    int input(); // gets data for Matrix
    int input2();
    void display(int n); //Displays the matrix
    int display2(int n);
    int retrieve(int row, int col); //Retrieving data from one location of matrix
    int retrieve2(int n);
    //int sub(int n); //function for negation
    //int mult(int n); //function for multiplication
    void setValue(int n, int row, int col); //function to Set a value at a specific location
    int setValue2(int n);
    //operator overload
    mcalc operator*(const mcalc& rhs) const;
    mcalc operator*(int scalar) const;
    mcalc operator-(const mcalc& rhs) const;

};
#endif