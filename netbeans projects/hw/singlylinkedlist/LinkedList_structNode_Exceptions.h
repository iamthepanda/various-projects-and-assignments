#ifndef LinkedList_structNode_Exceptions_H
#define LinkedList_structNode_Exceptions_H

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

//list index is out of range
class ExceptOOR : public out_of_range {
public:
    ExceptOOR(const string & message = ""): out_of_range(message.c_str()) {
    }
};

class ExceptLogic : public logic_error {
public:
    ExceptLogic(const string & message = ""): logic_error(message.c_str()) {
    }
};

#endif