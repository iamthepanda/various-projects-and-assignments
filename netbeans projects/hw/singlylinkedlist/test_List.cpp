/* 
 * File:        test_List.cpp
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 *
 * Created on May 8, 2015
 */
#include "List.h"

int main() {
    LinkedList a, b;
    
    //inserts values 8, 3, 7, 29 to the front of the list
    a.insertNumber(8);
    a.insertNumber(3);
    a.insertNumber(7);
    a.insertNumber(29);
    cout << "insert number and put operator" << endl;
    cout << a << endl;
    
    //copies the nodes of list a into list b
    cout << "assignment operator" << endl;
    b = a;
    cout << b << endl;
    
    //deletes the value at the third position
    a.deleteNumber(3);
    cout << "delete number" << endl;
    cout << a << endl;
    
    //reverses the order of list a
    cout << "reverse a" << endl;
    a.reverse(); //test the reverses() method
    cout << a << endl;

    //checks list a for specific integer values
    cout << "check" << endl;
    a.check(29, a);
    a.check(3, a);
    cout << endl;
    
    //return the size of list a
    cout << "the size of list a is "<<a.getSize()<<endl;
    cout << endl;
    
    //printing the original list which was copied into list b with the modified list a
    cout << "original list" << endl;
    cout << b << endl;
    cout << "modified list" << endl;
    cout << a << endl;
    
    return 0;
}