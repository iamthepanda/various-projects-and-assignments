/* George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans Cygwin gcc
 * 02.26.2015
 * HW 2 Matrix Multiplication
 */

#include <iostream>
#include <vector>
using namespace std;
std::vector< vector<int> > multiply_matrices(vector< vector<int> >& m1, vector< vector<int> >& m2);

int main() {
    int temp = 0;
    int arow = 0;
    int acol = 0;
    int brow = 0;
    int bcol = 0;
    
    cout << "This program calculates the product of user entered matrices. \n";
    cout << "Enter number of rows for matrix A: ";
    cin >> arow;
    cout << "Enter number of column for matrix A: ";
    cin >> acol;
    cout << "Enter number of rows for matrix B: ";
    cin >> brow;
    cout << "Enter number of columns for matrix B: ";
    cin >> bcol;
    
    // checks if the columns match the rows
    if (acol == brow) {
        std::vector< vector<int> > A(arow, vector<int>(acol));
        std::vector< vector<int> > B(brow, vector<int>(bcol));
        std::vector< vector<int> > C(arow, vector<int>(bcol)); // product of the matrices A and B
        cout << "Please enter in the contents of your first matrix:\n" << "Only integers are allowed.\n";
        for (int row = 0; row < arow; row++) {
            for (int col = 0; col < acol; col++) {
                cout << "Enter value at A[" << row << "]" << "[" << col << "]: ";
                cin >> A[row][col];
            }
        }
        
        cout << "----------------\n"; // display purposes
        cout << "Please enter in the contents of your second matrix:\n" 
                << "Only integers are allowed.\n";
        for (int row = 0; row < brow; row++) {
            for (int col = 0; col < bcol; col++) {
                cout << "Enter value at B[" << row << "]" << "[" << col << "]: ";
                cin >> B[row][col];
            }
        }
        
        cout << "----------------\n";
        cout << "Your first matrix:" << endl;
        for (int row = 0; row < arow; row++) {
            for (int col = 0; col < acol; col++) {
                cout << A[row][col] << " ";
            }
            cout << endl;
        }
        
        cout << "----------------\n";
        cout << "Your second matrix:" << endl;
        for (int row = 0; row < brow; row++) {
            for (int col = 0; col < bcol; col++) {
                cout << B[row][col] << " ";
            }
            cout << endl;
        }
        
        
        cout << "----------------\n";
        C = multiply_matrices(A, B);
        cout << "The product of the matrices:" << endl;
        
        for (int row = 0; row < C.size(); row++) {
            for (int col = 0; col < C[0].size(); col++) {
                cout << C[row][col] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "----------------\n";
        // Tells user if parameters are not met
        cout << "Error! Dimensions are not compatible. Terminating program" << endl;
    }
    return 0;
}

vector< vector<int> > multiply_matrices(vector< vector<int> >& m1, vector< vector<int> >& m2) {
    std::vector< vector<int> > m3(m1.size(), vector<int> (m2[0].size()));
    for (int row = 0; row < m1.size(); row++) {
        for (int col = 0; col < m2[0].size(); col++) {
            for (int inner = 0; inner < m2.size(); inner++) {
                m3[row][col] += m1[row][inner] * m2[inner][col];
            }
        }
    }
    return m3;
}
