/*/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: recursive recursion of arrays
 */
#include"newfile.h"
#include <iostream>
using namespace std;

recursion::recursion() {
    for (int i = 0; i < 100; i++)
        fixedArray[i] = 0;
    for (int i = 0; i < 100; i++)
        fixedArray[i] = 0;
}

//asks an end user to provide a list of integers from the keyboard
//and stores these numbers into the fixed-size array

void recursion::askUser() {
    cout << "provide the size of the list of integers up to 100: ";
    cin >> size;
    cout << "provide a list of integers: ";
    for (int i = 0; i < size; i++)
        cin >> fixedArray[i];
    
    cout << "enter a k: ";
    cin >> k;
    cout << "INPUT ACCEPTED";
}

//recursively prints out the array in reverse order
//if the array contains the number 4, 19, and 17.
//function will print out: 17, 19, 4. 

void recursion::printReverse(int index) {
    if (index == (-1)) {
        cout << "\nTHE ARRAY HAS BEEN REVERSED";
    } else {
        cout << fixedArray[index];
        printReverse(index - 1);
    }
}

//recursively searches the largest number in the array. 
//This function will return not only the value of the largest number 
//but also its index in the array.

returnLargest recursion::findLargest(int index, int tempLarge) {
    returnLargest theLargest;
    if (index == (-1)) {
        theLargest.index = index + 1;
        theLargest.tempLarge = tempLarge;
        cout << theLargest.tempLarge << " is the largest, and " << theLargest.index << " is the index ";
        return theLargest;
    } else {
        if (fixedArray[index] > tempLarge)
            tempLarge = fixedArray[index];
        findLargest(index - 1, tempLarge);
    }
}

//recursively finds the value of the k-th smallest number in the array, 
//where k is provided by the end-user. 
//partition-based, recursive algorithm.

int recursion::findK(int k, int startindex, int endindex) {
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = fixedArray[i];
    int p = startindex;
    int tempS = startindex;
    int tempE = endindex;
    int front = 0;
    for (int i = startindex + 1; i <= tempE; i++) //implement of the partition algorithm
    {
        if (fixedArray[i] > fixedArray[p]) {
            a[startindex] = fixedArray[i]; //put the larger number in front, small numbers at the end
            startindex++;
            front++; //record how many number is in front of the pivot number
        } else {
            a[endindex] = fixedArray[i];
            endindex--;
            //	front++;
        }
    }
    a[startindex] = fixedArray[p];
    for (int i = 0; i < size; i++)
        fixedArray[i] = a[i];

    if (k == front + 1) {
        cout << a[startindex];
        return a[startindex]; //base case
    } else if (k < front + 1)
        return findK(k, tempS, startindex - 1); //recursive 
    else if (k > front + 1)
        return findK(k - front - 1, startindex + 1, tempE); //recursive
}

void recursion::increasingOrder(int startindex, int endindex) {
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = fixedArray[i];
    int p = startindex;
    int tempS = startindex;
    int tempE = endindex;
    for (int i = startindex + 1; i <= tempE; i++) //implement of the algorithm
    {
        if (fixedArray[i] < fixedArray[p]) {
            a[startindex] = fixedArray[i]; //put the larger number in front, small numbers at the end
            startindex++;
        } else {
            a[endindex] = fixedArray[i];
            endindex--;
        }
    }
    a[startindex] = fixedArray[p];
    cout << endl;
    for (int i = 0; i < size; i++) {
        fixedArray[i] = a[i];
        if(startindex ==endindex)
        cout << fixedArray[i];
    }
    if (tempS < startindex)
        increasingOrder(tempS, startindex - 1);
    if (tempE > endindex)
        increasingOrder(endindex + 1, tempE);
}

void recursion::decreasingOrder(int startindex, int endindex) {
    int a[size];
    for (int i = 0; i < size; i++)
        a[i] = fixedArray[i];
    int p = startindex;
    int tempS = startindex;
    int tempE = endindex;
    for (int i = startindex + 1; i <= tempE; i++) //implement of the algorithm
    {
        if (fixedArray[i] < fixedArray[p]) {
            a[startindex] = fixedArray[p]; //put the larger number in front, small numbers at the end
            startindex++;
        } else {
            a[endindex] = fixedArray[i];
            endindex--;
        }
    }
    a[startindex] = fixedArray[p];
    for (int i = 0; i < size; i++) {
        fixedArray[i] = a[i];
        cout << fixedArray[i];
    }
    if (tempS < startindex)
        increasingOrder(tempS, startindex - 1);
    if (tempE > endindex)
        increasingOrder(endindex + 1, tempE);
}

int recursion::getSizeOff() {
    int offSize;
    offSize = size - 1;
    return offSize;
}

int recursion::getK(){
    return k;
}

int* recursion::getArray() //using pointer to get the private array variable from the class
{
    int* pointer;
    pointer = fixedArray;
    return pointer;
}

ostream& operator<<(ostream& os, recursion& rec) //overloading the << operator
{
    int* pointer = rec.getArray(); //using static variable to implement the overloading 
    static int a = rec.getSizeOff() + 1;
    static int i = 0;
    os << *(pointer + i);
    i++;
    if (i < a) {
        return (os << rec);
    }
}