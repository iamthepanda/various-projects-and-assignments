#include "matrix.h"
#include <stdlib.h>
using namespace std;
//runs all the functions from other .cpp file

int main() {
    int choice, j, rocol, newValue, rowIn, colIn, scalar;
    mcalc M1, M2;
    cout << "Square Matrices\n\n";
    cout << "Please state the value of N for your N-by-N matrix: ";
    //cin>>rocol;
    rocol = 2;
    M1.getN(rocol);
    M1.input();
    cout << "This is your first matrix: \n";
    M1.display(M1.n);
    cout << "\nPlease enter same value N as you did earlier or errors will occur: ";
    M2.getN2(2);
    M2.input2();
    cout << "This is your second matrix: \n";
    M2.display2(M2.n);
    while (1) {
        cout << "\nNumber corresponds to function" << endl;
        cout << "1: Set new value\n2: Retrieve\n"
                "3: Multiply Scalar\n0: Exit\n";
        cout << "\nEnter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n------------ Set New----------\nMatrix1: \n";
                M1.display(M1.n);
                cout << "Enter new value: " << endl;
                cin>>newValue;
                cout << "Enter row: " << endl;
                cin>>rowIn;
                cout << "Enter column: " << endl;
                cin>>colIn;
                rowIn--;
                colIn--;
                M1.setValue(newValue, rowIn, colIn);
                cout << "The value at row "<<rowIn+1<<" column "<<colIn+1<<" is : ";
                j = M1.retrieve(rowIn, colIn);
                //cout<<j<<endl;
                cout << "\nThis is your changed matrix: \n";
                M1.display(M1.n);
                cout << "\n------------------------------\n";
                break;
                
            case 2:
                cout << "\n------- Retrieve Value -------\nMatrix: \n";
                M1.display(M1.n);
                cout << "Enter row: " << endl;
                cin>>rowIn;
                cout << "Enter column: " << endl;
                cin>>colIn;
                rowIn--;
                colIn--;
                cout << "\nThe value at row "<<rowIn+1<<" column "<<colIn+1<<" is : ";
                M1.retrieve(rowIn, colIn);
                cout << "\n------------------------------\n";
                break;
                
            case 3:
                cout << "\n--- Scalar Multiplication ----\nMatrix: \n";
                M1.display(M1.n);
                cout << "\nEnter a scalar: ";
                cin >> scalar;
                cout << "\n\nMultiplied: \n";
                M1=M1 *scalar;
                M1.display(M1.n);
                cout << "\n------------------------------\n";
                break;
            
            /*case 4:
                cout << "\n--- Matrix Multiplication ----\nMatrix1: ";
                P1.display();
                cout << "\nEnter a degree: ";
                cin >> power;
                cout << "\nCoefficient: ";
                cout <<P1.coefficient(power);
                cout << "\n--------------------------------\n";
                break;
                
            case 5:
                cout << "\n----------- Subtraction -----------\nPolynomial: ";
                P1.display();
                cout << "\nEnter a scalar:";
                cin >> scalar;
                cout << "\n\nDivided:";
                P3=P1 /scalar;
                cout << "\n--------------------------------\n";
                break;
                
            case 6:
                cout << "\n----------- Output -------------\nPolynomial: ";
                P1.display();
                cout << "\n\nOutput:";
                cout <<P1;
                cout << "\n--------------------------------\n";
                break;
                
            case 7:
                cout << "\n--------- Transpose ----------\nMatrix: \n";
                M1.display(M1.n);
                cout << "\n\nTransposed: ";
                
                cout << "\n--------------------------------\n";
                break;*/
                
            case 0: //If user selects 0, program ends.
                cout << "Program Terminated by user" << endl;
                exit(0);
            default:
                break;
        }
    }
    //M2.retrieve2(M2.n);

    //M2.setValue2(M2.n);
    //M2.display2(M2.n);
    //M1.sub(M1.n);
    //M2.mult(M1.n);
    mcalc test = M1*M2;
    test.display(M1.n);
    //matrix test = M1.operator *(M2);
    /*mcalc test1;
    mcalc test2;
    test1 = test1;*/
    return 0;
}