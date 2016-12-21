#ifndef Vector_h
#define Vector_h

#include <iostream>
//using namespace std;

class Vector_double {
private:
    int capacity;
    int size;
    double *ptr;

public:
    Vector_double();
    
    Vector_double(const Vector_double & that);
    Vector_double operator=(const Vector_double & that);
    ~Vector_double();
    
    void push_back(double r);
    void pop_back();
    void insert(int first, double r);
    void erase(int first);
    void erase(int first, int last);
    
    int getCapacity();
    void resize(int size);
    void shrink_to_fit();
    
    int getSize();
    bool isEmpty();
    
    friend std::ostream& operator<<(std::ostream& out, const Vector_double that);
};

#endif