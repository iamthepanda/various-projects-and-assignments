/* 
 * File:        List.cpp
 * Author:      George Jone
 * ID:          913177426
 * email:       jone@mail.sfsu.edu
 * Compiler:    GNU Cygwin g++
 *
 * Created on May 8, 2015
 */
#include "List.h"

//default constructor initializes size and head ptr

LinkedList::LinkedList() : size(0), head(NULL) {
}

//the "big-3"
//1. copy constructor

LinkedList::LinkedList(const LinkedList& aList) : size(aList.size) {
    if (aList.head == NULL) {
        head = NULL; //original list is empty
        size = 0;
    } else { //copy first node
        head = new ListNode;
        head->item = aList.head->item;

        //copy rest of list
        ListNode *newPtr = head; //new list pointer
        //newPtr points to last node in new list
        //origPtr points to nodes in original list
        for (ListNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        } //end for

        newPtr->next = NULL;
    } //end if
}

//2. copy assignment operator
//overload the assignment operator for copying heads

LinkedList LinkedList::operator=(const LinkedList& rhs) {
    if (rhs.head == NULL) {
        head = NULL; //original list is empty
        size = 0;
    } else { //copy first node
        head = new ListNode;
        head->item = rhs.head->item;

        //copy rest of list
        ListNode *newPtr = head; //new list pointer newPtr points to last node in new list

        //origPtr points to nodes in original list
        for (ListNode *origPtr = rhs.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        } //end for

        newPtr->next = NULL;
    }

    return *this;
}

//3. destructor

LinkedList::~LinkedList() {
    ListNode *curr = head;

    while (curr != NULL) {
        head = curr->next;
        delete []curr;
        curr = head;
    }
}

//find position

LinkedList::ListNode *LinkedList::find(int index) const {
    if ((index < 1) || (index > size))
        return NULL;

    else { //count from the beginning of the list.
        ListNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;

        return cur;
    } //end if
}

//inserts a number at the front of the list

void LinkedList::insertNumber(const ListItemType& newItem) throw (ExceptOOR, ExceptLogic) {
    int newLength = size + 1;

    try {
        ListNode *newPtr = new ListNode;
        size = newLength;
        newPtr->item = newItem;

        newPtr->next = head;
        head = newPtr;
    } catch (bad_alloc e) {
        throw ExceptLogic("ExceptLogic: memory allocation failed on insert");
    }
}

//deletes a number from the list, where this number can be located anywhere on the list.

void LinkedList::deleteNumber(int index) throw (ExceptOOR) {
    ListNode *cur;

    if ((index < 1) || (index > size))
        throw ExceptOOR("ExceptOOR: remove index out of range");
    else {
        --size;

        if (index == 1) { //delete []the first node from the list
            cur = head; //save pointer to node
            head = head->next;
        } else {
            ListNode *prev = find(index - 1);
            //delete []the node after the node to which prev points
            cur = prev->next; //save pointer to node
            prev->next = cur->next;
        }//end if

        //reset node
        cur->next = NULL;
        delete []cur;
        cur = NULL;
    }//end if
}

//checks whether an integer is on the list.

bool LinkedList::check(int value, LinkedList aList) {
    int a;

    while (aList.head != NULL) {
        a = aList.head->item;

        if (a == value) {
            cout << "the specified integer, "<< value <<", is contained within the list" << endl;
            return true;
        }

        aList.head = aList.head->next;
    }

    cout << "the specified integer, "<< value <<", is not contained within the list" << endl;
    return false;
}

//returns the size of the list.

int LinkedList::getSize() const {
    return size;
}

//reverses a linked list without recreating a temporary copy of this linked list.
//function CAN NOT use the 'new' operator.

void LinkedList::reverse() {
    ListNode *cur; //create a pointer of a Listnode. 
    cur = find(size); //make their next pointer point to its previdous address.

    for (int i = size; i > 1; i--)
        find(i)->next = find(i - 1);

    find(1)->next = NULL;
    head = cur;
}

//overload the << operator make a copy of the given List and print out the elements for in the List.
//an overloaded put operator (<<) to print out all the data items stored on a linked list

ostream& operator<<(ostream& os, LinkedList aList) {
    int a;

    while (aList.head != NULL) {
        a = aList.head->item;
        os << a << endl;
        aList.head = aList.head->next;
    }

    return os;
}