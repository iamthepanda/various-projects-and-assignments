/*/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: recursive recursion of arrays
 */

#ifndef NEWFILE_H
#define	NEWFILE_H
#include<iostream>

//allows the return of two values
struct returnLargest {
    int tempLarge;
    int index;
};

class recursion {
private:
    int fixedArray[100];    //array used in operations
    int size;   //size of the array
    int k;

public:
    recursion();    //default
    void askUser(); //function to gather input for original array
    void printReverse(int); //reverses the original array
    returnLargest findLargest(int, int);    //returns largest integer and its index
    int findK(int, int, int);   //finds the kth smallest number

    int getSizeOff();   //gets the size and offsets it by -1
    int *getArray();    //gets the array
    int getK(); //gets k

    //optional
    void increasingOrder(int, int); //quicksorts the array to increasing order
    void decreasingOrder(int, int); //quicksorts the array to decreasing order
    //friend 
    friend std::ostream& operator<<(std::ostream& os, recursion& rec);  //overload
};

#endif	/* NEWFILE_H */