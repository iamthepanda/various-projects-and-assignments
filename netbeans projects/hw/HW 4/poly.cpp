/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: initializes the functions within the class polynomial
 */
#include "poly.h"
#include<string>
using namespace std;

polynomial::polynomial() {
}

//display used to format the output of the polynomial
string polynomial::display() {
    string s;
    int sumx = 0;
    int newMax = maxDegree; //newMax used to correctly account for first coefficient being 0

    for (int i = maxDegree; i >= 0; i--) { //using i-- to check descending maxDegree, start with highest
        if (coeff[i] == 0) {
            sumx = sumx + coeff[i];

            if (i == 0 && sumx == 0) {
                cout << sumx;
            }

            newMax--;

            continue; //goes to next degree of the polynomial if the coefficient is 0
        } else if (i == newMax || coeff[i] < 0) {
            if (i > 1) {
                cout << coeff[i] << "x^" << i;
            } else if (i == 1) {
                if (coeff[i] == 1) {
                    cout << "x";
                } else {
                    cout << coeff[i] << "x";
                }
            } else {
                cout << coeff[i];
            }
        } else {
            if (i > 1) {
                cout << "+" << coeff[i] << "x^" << i;
            } else if (i == 1) {
                if (coeff[i] == 1) {
                    cout << "+" << "x";
                } else {
                    cout << "+" << coeff[i] << "x";
                }
            } else {
                cout << "+" << coeff[i];
            }
        }
    }

    return s;
}

//returns maxDegree
int polynomial::degree() {
    return maxDegree;
}

//returns the coefficient corresponding to power
int polynomial::coefficient(int power) {
    return coeff[power];
}

//changes the coefficient corresponding to power to newCoefficient
polynomial polynomial::changeCoefficient(int newCoefficient, int power) {
    polynomial changed;

    changed.maxDegree = maxDegree;

    for (int i = 0; i <= maxDegree; i++) {
        changed.coeff[i] = coeff[i];
    }

    changed.coeff[power] = newCoefficient;
    changed.display();

    return changed;
}

//function to receive input data from user
int polynomial::get_data() {
    cin >> maxDegree;

    for (int i = maxDegree; i >= 0; i--) {
        cout << "Enter coefficient of x^" << i << ":";
        cin >> coeff[i];
    }

    return 0;
}

//function to add polynomials using data given by the user
polynomial polynomial::addition(polynomial P2) {
    polynomial sum;
    int max = 0;

    if (maxDegree > P2.maxDegree) { // if if maxDegrees don't agree follow polynomial order of operations in calculations
        max = maxDegree;
    } else {
        max = P2.maxDegree;
    }
    sum.maxDegree = max;

    for (int i = 0; i <= max; i++) {
        sum.coeff[i] = coeff[i] + P2.coeff[i];
    }

    sum.display();

    return sum;
}

//function to overload the - operator to negate the given polynomial object from user
polynomial polynomial::operator-() const {
    polynomial neg;

    neg.maxDegree = maxDegree;

    for (int i = 0; i <= maxDegree; i++) {
        neg.coeff[i] = -coeff[i];
    }

    neg.display();

    return neg;
}

//function to overload the * operator to multiply given polynomial object from user
polynomial polynomial::operator*(int scalar) const {
    polynomial mul;

    mul.maxDegree = maxDegree;

    for (int i = 0; i <= maxDegree; i++) {
        mul.coeff[i] = coeff[i] * scalar;
    }

    mul.display();

    return mul;
}

//function to overload the / operator to divide given polynomial object from user
polynomial polynomial::operator/(int dScale) const {
    polynomial div;

    div.maxDegree = maxDegree;

    for (int i = 0; i <= maxDegree; i++) {
        div.coeff[i] = coeff[i] / dScale;
    }

    div.display();

    return div;
}

//function to overload the << operator to output a given polynomial object from user using cout
ostream& operator<<(std::ostream& out, polynomial obj) {
    out << obj.display();

    return out;
}