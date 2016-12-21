#include "Vector.h"
#include <iostream>

using namespace std;

Vector_double::Vector_double() : size(0), capacity(0), ptr(NULL) ///the constructor with a initial value size =0 and capacity 0 
{}

Vector_double::Vector_double(const Vector_double& a) : size(a.size), capacity(a.capacity)//copy constructor
{
    if (capacity <= 0)
        ptr = NULL;
    else {
        ptr = new double [capacity]; //copy every element to the new ptr.
        for (int i = 0; i < size; i++)
            ptr[ i ] = a.ptr[ i ];
    }
}

Vector_double Vector_double::operator=(const Vector_double & rhs) //overload equal operator
{
    if (capacity > 0) {
        delete [] ptr;
    }
    size = rhs.size;
    capacity = rhs.capacity;
    if (capacity <= 0)
        ptr = NULL;
    else {
        ptr = new double[capacity];
        for (int i = 0; i < size; i++)
            ptr[i] = rhs.ptr[i];
    }

}

Vector_double::~Vector_double() //destrutor 
{
    if (ptr != NULL) {
        delete [] ptr;
        ptr = NULL;
        size = 0;
        capacity = 0;
    }
}

int Vector_double::getCapacity() //return capacity
{
    return capacity;
}

bool Vector_double::isEmpty() //check if there is a element in the ptr or not
{
    if (size == 0)
        return true;
    else
        return false;
}

void Vector_double::push_back(double r) //add one rber into the ptr and increase the size by 1. if the ptr has no enough space replace with a bigger one
{
    if (capacity == 0) {
        ptr = new double[1];
        ptr[0] = r;
        size++;
        capacity++;
    } else if (capacity > size) //if there is enough space in the ptr. just add one more value to the ptr and increase the size by one.
    {
        ptr[size] = r;
        size++;
    } else {
        double *temp = NULL;
        try {
            temp = new double[capacity + 1];
        } catch (bad_alloc& e) {
            cerr << "Vector_double push_back: " << e.what();
        }

        for (int i = 0; i < size; i++) //replacing elements
        {
            temp[i] = ptr[i];
        }
        temp[size] = r;
        delete [] ptr;
        ptr = temp;
        size++;
        capacity++;
    }

}

ostream& operator<<(ostream& os, const Vector_double a) //overload the << operator, for every element in the ptr.
{
    for (int i = 0; i < a.size; i++) //replacing elements
        os << a.ptr[i] << endl;
    return os;
}

void Vector_double::erase(int first) //implement the erase method. remove the element from the ptr at specific firstition.
{
    double * temp = new double[capacity];
    
    for (int i = 0; i < first; i++) //replacing elements
    {
        temp[i] = ptr[i];
    }
    for (int i = first; i < size - 1; i++) //replacing elements
    {
        temp[i] = ptr[i + 1];
    }
    delete [] ptr;
    ptr = temp;
    size--;


}

void Vector_double::erase(int first, int last) //implement the erase method for the range version. remove elelments in specifc range.
{
    double *temp = new double[capacity];
    for (int i = 0; i < first; i++) //replacing elements
    {
        temp[i] = ptr[i];
    }
    for (int i = first; i < size - last + first; i++) //replacing elements
    {
        temp[i] = ptr[i + last - first];
    }
    delete []ptr;
    ptr = temp;
    size = size - last + first;
}

void Vector_double::insert(int first, double r) //implement the insert method which add a specific element into specific firstision. 
{
    double *temp;
    if (capacity > size) {
        temp = new double[capacity];
    } else {
        temp = new double[capacity + 1];
        capacity++;
    }

    for (int i = 0; i < first; i++) //replacing elements
    {
        temp[i] = ptr[i];
    }
    temp[first] = r;
    for (int i = first; i < size; i++) //replacing elements
    {
        temp[i + 1] = ptr[i];
    }
    delete [] ptr;
    ptr = temp;
    size++;
}

void Vector_double::pop_back() //remove the last element in the ptr.
{
    if (size > 0)
        size--;
    else
        size = 0;
}

int Vector_double::getSize() //return size
{
    return size;
}

void Vector_double::resize(int size) //implementation of resize if the size is bigger than we need we create a bigger ptr, 
//else we change just the size of the original ptr
{
    if (size > size) {
        size = size;
    } else if (size < size) {
        double *temp = new double[size];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i]; //replacing elements
        }
        for (int i = size; i < size; i++) //insert 0 elements
        {
            temp[i] = 0;
        }
        delete [] ptr;
        ptr = temp;
        size = size;
        capacity = size;
    }
}

void Vector_double::shrink_to_fit() //if the capacity is bigger than its size we replace it with a ptr that has the same capacity and size. 
{
    if (capacity > size) {
        double *temp = new double[size];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        delete [] ptr;
        ptr = temp;
        capacity = size;
    }
}

