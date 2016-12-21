//#include <iostream>
//#include <vector>
#include "matrix.h"
using namespace std;
//function to get N for NxN Dimension matrix

mcalc::mcalc() {
    //size of matrix is set to 0 by 0 by default
    nmatrix.resize(0);
    for(int i=0;i<nmatrix.size();i++){
        nmatrix[i].resize(0);
    }
}
mcalc::mcalc(std::vector<std::vector<int> > somevector){
    
}

void mcalc::getN(int matSize) {
    n = 2;
    cout << n<<endl;
    nmatrix.resize(n);
    for (int i = 0; i < n; i++)
        nmatrix[i].resize(n);
    /*nmatrix.resize(2);
    nmatrix[0].resize(2);*/
}

void mcalc::getN2(int matSize) {
    n = 2;
    cout << n<<endl;

    mmatrix.resize(n);
    for (int i = 0; i < n; i++)
        mmatrix[i].resize(n);
    /*mmatrix.resize(2);
    mmatrix[0].resize(2);*/
}
//getting user input

// display matrix 1

void mcalc::display(int n) {
    // vector< vector<int> > nmatrix(n, vector<int>(n)); //ignore this
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << nmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
//display matrix 2

int mcalc::display2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mmatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//retrieving value at location for matrix 1

int mcalc::retrieve(int row, int col) {
    cout << nmatrix[row][col] << endl;
    return nmatrix[row][col];
}
//retrieving value at location for matrix 2

int mcalc::retrieve2(int n) {
    int row, col;
    cout << "What value would you like to know from second Matrix? \n";
    cout << "Row 1 = 0\n";
    cout << "What row would you like to check? \n";
    cin >> row;
    cout << "What col would you like to check? \n";
    cin >> col;
    cout << "The value is : " << mmatrix[row][col] << endl;
}
//set value for location in matrix 1

void mcalc::setValue(int n, int row, int col) {

    nmatrix[row][col] = n;
}
//set value for location in matrix 2

int mcalc::setValue2(int n) {
    int row, col, num;
    cout << "Setting a new value to a location for First Matrix \n ";
    cout << "Row 1 = 0\n";
    cout << "Which row would you like to set? \n";
    cin >> row;
    cout << "which col would you like to check? \n";
    cin >> col;
    cout << "what value would you like to set this location with? \n";
    cin >> num;
    mmatrix[row][col] = num;
}

//void mcalc::resize(){
    
//}
//matrix negation function

/*int mcalc::sub(int n) {
    cout << "This is the difference of the two Matrices: \n";
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            difference[row][col] = nmatrix[row][col] - mmatrix[row][col];
            cout << difference[row][col] << " ";
        }
        cout << "\n";
    }
}*/

//matrix product function
mcalc mcalc::operator*(int scalar) const{
    //cout << "This is the Product of the two Matrices: \n";
    mcalc scaled;
    scaled.getN(n);
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            //for (int inner = 0; inner < n; inner++) {
                scaled.nmatrix[row][col]=nmatrix[row][col] *scalar;
            //}
            //cout << product[row][col] << " ";
        }
        //cout << "\n";
    }
    
}

int mcalc::input() {
    int count = 1, content = 1;
    //vector< vector<int> > nmatrix(n, vector<int>(n)); //ignore this
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << count << ": ";
            //cin>>content;
            cout << content << endl;
            nmatrix[i][j] = content;
            
            content++;
            count++;
        }
    }
    return 0;
}
//getting user input for matrix 2

int mcalc::input2() {
    int count = 1, content = 0;
    //vector< vector<int> > nmatrix(n, vector<int>(n)); //ignore this
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << count << ": ";

            cout << content << endl;
            mmatrix[i][j] = content;
            count++;
        }
    }
    return 0;
}

mcalc mcalc::operator*(const mcalc& rhs) const{
    mcalc multi;
    multi.nmatrix = nmatrix;
    //multi.getN();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k;k<n;k++){
                multi.nmatrix[i][j] = nmatrix[i][k] * rhs.nmatrix[k][j];
            }
        }
    }
    return multi;
}
