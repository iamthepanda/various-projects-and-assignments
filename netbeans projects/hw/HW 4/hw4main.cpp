/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 */
#include <stdlib.h> //for terminating program when user specifies
#include "poly.h"
using namespace std;

int main() {
    int choice, scalar, power, newCoeff;

    //ADT variables for 3 polynomials. P1, P2 for input and P3 for output
    polynomial P1, P2, P3;

    cout << "Enter Polynomial 1: \nEnter Degree Of Polynomial: ";
    
    P1.get_data(); //accessing get_data() function specifically for P1
    
    cout << endl;

    cout << "Enter Polynomial 2: \nEnter Degree Of Polynomial: ";
    
    P2.get_data();

    //Prompts user for choice of calculation using switch
    while (1) {
        cout << "\nNumbers correspond to functionality" << endl;
        cout << "\n1: Addition\n2: Negation\n3: Multiplication\n4: Division"
                "\n5: Output\n6: Highest Degree\n7: Show Coefficient"
                "\n8: Coefficient Changer\n0: Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n------------ Addition ----------\n";
                cout << "Polynomial 1: " << P1;
                cout << endl;
                cout << "Polynomial 2: " << P2;
                
                cout << "\n\nAdded: ";
                
                P3 = P1.addition(P2);
                
                cout << "\n--------------------------------\n";
                break;

            case 2:
                cout << "\n----------- Negation -----------\n";
                cout << "Polynomial 1: " << P1;
                cout << "\n\nNegated: ";
                
                P3 = -P1;
                
                cout << "\n--------------------------------\n";
                break;

            case 3:
                cout << "\n-------- Multiplication --------\n";
                cout << "Polynomial 1: " << P1;
                cout << "\nEnter a scalar:";
                
                cin >> scalar;
                
                cout << "\n\nMultiplied: ";
                
                P3 = P1 *scalar;
                
                cout << "\n--------------------------------\n";
                break;

            case 4:
                cout << "\n----------- Division -----------\n";
                cout << "Polynomial 1: " << P1;
                cout << "\nEnter a scalar:";
                
                cin >> scalar;
                
                cout << "\n\nDivided:";
                
                P3 = P1 / scalar;
                
                cout << "\n--------------------------------\n";
                break;

            case 5:
                cout << "\n----------- Output -------------\n";
                cout << "Polynomial 1: ";
                
                cout << P1;
                
                cout << "\n--------------------------------\n";
                break;

            case 6:
                cout << "\n----------- Degree -------------\n";
                cout << "Polynomial 1: " << P1;
                cout << "\n\nHighest degree in Polynomial 1: " << P1.degree();
                
                cout << "\n--------------------------------\n";
                break;

            case 7:
                cout << "\n------ Show Coefficient --------\n";
                cout << "Polynomial 1: ";
                cout << P1;
                cout << "\nEnter a degree: ";
                
                cin >> power;
                
                cout << "\nCoefficient: " << P1.coefficient(power);
                
                cout << "\n--------------------------------\n";
                break;

            case 8:
                cout << "\n----- Coefficient Changer ------\n";
                cout << "Polynomial 1: ";
                cout << P1;
                cout << "\nEnter a degree: ";
                
                cin >> power;
                
                cout << "Enter a new coefficient: ";
                
                cin >> newCoeff;
                
                cout << "\nChanged Coefficient: ";
                
                P3 = P1.changeCoefficient(newCoeff, power);
                
                cout << "\n--------------------------------\n";
                break;

            case 0: //If user selects 0, program ends.
                cout << "Program Terminated by user" << endl;
                exit(0);
                
            default:    //default case to catch exceptions
                break;
        }
    }
    
    return 0;
}