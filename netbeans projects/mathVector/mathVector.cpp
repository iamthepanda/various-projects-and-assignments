/* 
 * File:   mathVector.cpp
 * Author: George
 *
 * Created on March 3, 2015, 12:01 PM
 * implement the member functions in the class mathVector
 */

#include "mathVector.h"

mathVector::mathVector():size(0),type(vectorType::row),container(100000)
{
    //size = 0;
    //type = vectorType::row;
    for (int i=0; i<MAXSIZE; i++)
        mv[i] = 0;
}
mathVector::mathVector(int mv_size):size(int mv_size),type(vectorType::row)
{
    //size = 0;
    //type = vectorType::row;
    for (int i=0; i<MAXSIZE; i++)
        mv[i] = 0;
}

int mathVector::get_size()
{
    return size;
}

vectorType mathVector::get_type()
{
    return type;
}