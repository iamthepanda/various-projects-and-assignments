/* 
 * File:        List.h
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 *
 * Created on May 8, 2015
 */
#include <iostream>
#include "LinkedList_structNode_Exceptions.h"

typedef int ListItemType;

//pointer-based list abstract data type

class LinkedList {
private:
    int size; //number of elements in list.
    //node data item and pointer to next node

    struct ListNode {
        ListItemType item; //element on the list.
        ListNode *next; //pointer to next node.
    };
    
    ListNode *head; //pointer to head of linked list
    ListNode *find(int index) const; //locates a specific node in the linked list

public:
    LinkedList(); //default constructor

    //the "big-3"
    LinkedList(const LinkedList& aList); //1. copy constructor
    LinkedList operator=(const LinkedList& rhs); //2. copy assignment operator
    ~LinkedList(); //3. destructor

    void insertNumber(const ListItemType& newItem) throw (ExceptOOR, ExceptLogic);  //inserts a number at the front of the list
    void deleteNumber(int index) throw (ExceptOOR);    //deletes a number from the list, where this number can be located anywhere on the list.
    bool check(int value, LinkedList aList);    //checks whether an integer is on the list.
    int getSize() const;  //returns the size of the list.
    friend ostream & operator<<(ostream & out, LinkedList that);  //an overloaded put operator (<<) to print out all the data items stored on a linked list.
    void reverse();    //reverses a linked list without recreating a temporary copy of this linked list
};
