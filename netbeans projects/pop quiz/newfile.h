/* 
 * File:   newfile.h
 * Author: george
 *
 * Created on May 5, 2015, 11:12 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

class List{
    List(const List& aList);
    
    List operator=(const List& rhs);
    
    ~List();
    
    void createList(int k);
    
    bool isEmpty() const;
    int getLength( const);
    void insert(int index, const ListItemType& newItem);
    throw (ListIndexOutofRangeException, ListException);
};

class ListNode{
    
};

#endif	/* NEWFILE_H */

