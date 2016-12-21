/*/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: declare the interface of the class polynomial
 *              which will be instantiated into objects of polynomials
 */
#ifndef POLY_H
#define POLY_H
#include<iostream>
#include<string>

class polynomial {
private:
    int maxDegree;
    double coeff[100]; //100 should be a practical number of coefficients to store

public:
    //constructor
    polynomial();

    //accessors
    int get_data(); //gets the size of the polynomial
    int degree(); //return the value of maxDegree
    int coefficient(int power);
    std::string display();

    //mutators
    polynomial changeCoefficient(int newCoefficient, int power);
    polynomial addition(polynomial P2);

    //overload operators
    polynomial operator*(int scalar) const;
    polynomial operator/(int scalar) const;
    polynomial operator-() const;
    friend std::ostream& operator<<(std::ostream& out, polynomial obj);
};

#endif