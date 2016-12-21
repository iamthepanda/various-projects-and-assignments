/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 */
#include "matrix.h"
using namespace std;

//initailizes to 0
Matrix::Matrix() : matrix(0, vector<float>(0)){
}

//initializes the value stored in the vector of vector
Matrix::Matrix(const vector<vector<float> >& v) : matrix(v){
}

//set the number of rows and number of columns of a matrix to a and initialize all elements to 0
void Matrix::blankMatrix(int a){
    vector<vector <float> > m;
    
    for (int i = 0; i < a; i++) {
        vector<float> m1; //create a float vector
        
        for (int j = 0; j < a; j++) {
            m1.push_back(0);
        }
        
        m.push_back(m1); //wrap vector in another vector
    }
    
    matrix = m;
}

//get the number in the matrix at the specified row and col
float Matrix::getNum(int row, int col) const {
    return matrix[row - 1][col - 1];    //account for offset
}

//set the number in the matrix at the specified row and col
void Matrix::setNum(int row, int col, int num){
    matrix[row - 1][col - 1] = num;    //account for offset
}

//transpose the matrix
void Matrix::transpose(){
    vector< vector<float> > m;
    
    m = matrix;
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = m[j][i];
        }
    }
}

//function to overload the * operator to multiply given Matrix object from user
Matrix Matrix::operator*(const Matrix& rhs) const {
    Matrix m;
    
    if (matrix.size() == rhs.matrix.size()) // if they have the same dimen  do the multiplication else return "can not do it"
    {
        m.blankMatrix(matrix.size());
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                for (int columnA = 0; columnA < matrix[0].size(); columnA++) {
                    m.matrix[i][j] = m.matrix[i][j] + matrix[i][columnA] * rhs.matrix[columnA][j]; //put the sum of the product of A's row and B's column in the result matrix.
                }
            }
        }
        
        return m;
    } else{
        cout << "Dimensions do not match. Return to default matrix" << endl;
    }
    
    return m;
}
//An overloaded multiplication operator (*) as a member function to multiply a matrix by a scalar variable given by the user 
Matrix Matrix::operator*(float scalar) const {
    Matrix m;
    
    m.blankMatrix(matrix.size());
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            m.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    
    return m;
}

//function to overload the - operator to subtract the given Matrix object from user
Matrix Matrix::operator-(const Matrix& rhs) const {
    Matrix m;
    
    if (matrix.size() == rhs.matrix.size()) {
        m.blankMatrix(matrix.size());
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                m.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
            }
        }
    } else{
        cout << "Cannot subtract because matrix dimensions do not match. Return to default matrix" << endl;
    }
    
    return m;
}

//function to overload the << operator to output a given Matrix object from user using cout
ostream& operator<<(ostream& os, const Matrix& rhs) {
    for (int i = 0; i < rhs.matrix.size(); i++) {
        for (int j = 0; j < rhs.matrix.size(); j++) {
            os << rhs.matrix[i][j] << " ";
        }
        
        os << endl;
    }
    
    return os;
}