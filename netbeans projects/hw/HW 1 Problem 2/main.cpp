/*George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans Cygwin gcc
 * 02.18.2015
 * HW1
 */
/*Problem 2
 * Implement another C++ program to sort a list of integers using the selection sort algorithm. You are required to:
 * use an integer vector to store the input numbers typed from the keyboard. The declaration of this vector will be in main().
You'll need to implement a separate function readData() to read numbers from the keyboard;
 * implement a separate function called selectionSort(), which will be called by the main() function to sort the afore-mentioned vector;
 * implement another function printVector() to print out the content of the vector. This function will be called by main() right after
calling readData() and selectionSort(), respectively, to print out the vector content before and after being sorted.
*/

#include "newfile.h"
using namespace std;

// function gets the numbers from user for sorting
void readData(vector<int> &vectorReference) {
    int input = 0;
    int amount = 0;
    
    while (!(cin >> amount) || amount < 2 || amount > numeric_limits<streamsize>::max()) {
        cin.clear();    // so inputs are reset after each iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter amount of numbers you want to sort, at least 2\n";
    }
    cout << "\nReady to sort: " << amount << " numbers.\n\n";
    
    cout << "Enter your numbers and press [ENTER] after each number\n";
    for (int i = 0; i < amount; i++) {
        input = 0;
        
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That is not a number. Enter a number this time: \n";
        }
        
        vectorReference.push_back(input);
    }
};

// print the value at vectorReference
void printVector(vector<int> &vectorReference) {
    for (int i = 0; i < vectorReference.size() - 1; i++)
        cout << vectorReference[i] << ", ";
    
    cout << vectorReference[vectorReference.size() - 1];
};

// sorts the numbers from lowest to highest
void selectionSort(vector<int> &vectorReference) {
    int index = 0;
    int temp = 0;
    
    for (int i = 0; i < vectorReference.size(); i++) {
        index = i;
        
        for (int j = i + 1; j < vectorReference.size(); j++) {
            if (vectorReference[j] < vectorReference[index]) 
                index = j;
        }
        
        if (index != i) {
            temp = vectorReference[i];
            vectorReference[i] = vectorReference[index];
            vectorReference[index] = temp;
        }
    }
};

int f(int x){
    
    return 1;
}

int main() {
    vector<int> intVector;
    int x;
    int i;
    
    cout << "Enter amount of numbers you want to sort, at least 2\n";
    readData(intVector);
    
    cout << "\nHere are the numbers you entered:        ";
    printVector(intVector);
    
    cout << "\nHere are the numbers you entered sorted: ";
    selectionSort(intVector);
    printVector(intVector);
    
    cout << "\n";
    
    return 0;
}