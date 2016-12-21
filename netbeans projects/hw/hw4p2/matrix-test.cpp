/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 */
#include "matrix.h"
#include <stdlib.h> //allows user to terminate program from switch
using namespace std;

int main(int argc, char** argv) {
    Matrix m1, m2;
    int choice, rocol, newValue, rowIn, colIn, scalar;

    cout << "Matrices" << endl << endl;
    cout << "Enter desired size of square matrix (minimum 2): ";
    
    cin>>rocol;
    
    cout << "\nThis is a blank square matrix of size " << rocol << ": " << endl;
    m1.blankMatrix(rocol);  //makes a blank matrix m1 of size rocol
    cout << m1;

    cout << "\nThe values in matrix 1 and matrix 2 will now be preset:" << endl;
    cout << "\nMatrix 1:" << endl;
    m1.setNum(1, 1, 5);
    m1.setNum(1, 2, 6);
    m1.setNum(2, 1, 7);
    m1.setNum(2, 2, 8);
    cout << m1;
    
    cout << "\nMatrix 2:" << endl;
    m2.blankMatrix(rocol);
    m2.setNum(1, 1, 2);
    m2.setNum(1, 2, 3);
    m2.setNum(2, 1, 4);
    m2.setNum(2, 2, 5);
    cout << m2;

    while (1) {
        cout << "\nNumber corresponds to functions to operate on Matrix 1" << endl;
        cout << "1: Set new value\n2: Retrieve\n3: Multiply scalar\n"
                "4: Multiply Matrix 1 by Matrix 2\n"
                "5: Subtract Matrix 1 by Matrix 2\n6: Output\n7: Transpose\n"
                "0: Exit\n";
        cout << "\nEnter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n----------- Set New ----------\n";
                cout << "Matrix 1: \n" << m1;
                cout << "\nEnter a row number " << "(1-" << rocol << "): ";
                
                cin>>rowIn;
                
                cout << "\nEnter a column number " << "(1-" << rocol << "): ";
                
                cin>>colIn;
                
                cout << "\nEnter a new value: ";
                
                cin>>newValue;

                m1.setNum(rowIn, colIn, newValue); //sets the values in m1
                cout << m1;
                
                cout << "\n------------------------------\n";
                break;

            case 2:
                cout << "\n------- Retrieve Value -------\n";
                cout << "Matrix 1: \n" << m1;
                cout << "\nEnter a row number " << "(1-" << rocol << "): ";
                
                cin>>rowIn;
                
                cout << "\nEnter a column number " << "(1-" << rocol << "): ";
                
                cin>>colIn;

                cout << "\nThe value at row " << rowIn << " col " << colIn << " is: ";
                cout << m1.getNum(rowIn, colIn) << endl;
                
                cout << "\n------------------------------\n";
                break;

            case 3:
                cout << "\n--- Scalar Multiplication ----\n";
                cout << "Matrix 1: \n";
                cout << m1;
                cout << "\nEnter a scalar: ";
                
                cin >> scalar;
                
                m1 = m1 * scalar;
                
                cout << endl;
                cout << "Matrix 1 * " << scalar << " =\n";
                cout << m1;
                cout << "\n------------------------------\n";
                break;

            case 4:
                cout << "\n--- Matrix Multiplication ----\n";
                cout << "Matrix 1\n";
                cout << m1;
                cout << "\nMatrix 2\n";
                cout << m2;
                cout << endl;

                m1 = m1*m2;

                cout << "Matrix 1 * Matrix 2 =\n" << m1;
                
                cout << "\n--------------------------------\n";
                break;

            case 5:
                cout << "\n----------- Subtraction -----------\nMatrix: ";
                cout << "Matrix 1\n";
                cout << m1;
                cout << "\nMatrix 2\n";
                cout << m2;
                cout << endl;

                cout << "Matrix 1 - Matrix 2 =\n";
                
                m1 = m1 - m2;
                
                cout << m1;
                cout << endl;
                
                cout << "\n--------------------------------\n";
                break;

            case 6:
                cout << "\n----------- Output -------------\n";
                cout << "Matrix 1:\n";
                cout << m1;
                
                cout << "\n--------------------------------\n";
                break;

            case 7:
                cout << "\n--------- Transpose ----------\n";
                cout << "Matrix 1: \n" << m1;
                cout << "\nMatrix 1 transposed: \n";
                m1.transpose();
                cout<< m1;
                
                cout << "\n--------------------------------\n";
                break;

            case 0: //If user selects 0, program ends.
                cout << "Program Terminated by user" << endl;
                exit(0);
                
            default:
                break;
        }
    }
    
    return 0;
}