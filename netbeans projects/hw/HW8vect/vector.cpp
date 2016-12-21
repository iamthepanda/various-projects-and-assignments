#include "vector.h"

using namespace std;
/* Implementation section */

/*
 * Implementation notes: Vector constructor and destructor
 * -------------------------------------------------------
 * The constructor allocates storage for the dynamic array and initializes
 * the other fields of the object.  The destructor frees the memory used
 * for the array.
 */

Vector::Vector() {
    count = capacity = 0;
    elements = NULL;
}

Vector::Vector(int n, double value) {
    count = capacity = n;
    elements = (n == 0) ? NULL : new double[n];
    for (int i = 0; i < n; i++) {
        elements[i] = value;
    }
}

Vector::~Vector() {
    if (elements != NULL) delete[] elements;
}

/*
 * Implementation notes: Vector methods
 * ------------------------------------
 * The basic Vector methods are straightforward and should require no
 * detailed documentation.
 */

int Vector::size() const {
    return count;
}

bool Vector::isEmpty() const {
    return count == 0;
}

void Vector::clear() {
    if (elements != NULL) delete[] elements;
    count = capacity = 0;
    elements = NULL;
}

const double & Vector::get(int index) const {
    if (index < 0 || index >= count) error("get: index out of range");
    return elements[index];
}

void Vector::set(int index, const double & value) {
    if (index < 0 || index >= count) error("set: index out of range");
    elements[index] = value;
}

/*
 * Implementation notes: insert, remove, add
 * -----------------------------------------
 * These methods must shift the existing elements in the array to make room
 * for a new element or to close up the space left by a deleted one.
 */

void Vector::insert(int index, double value) {
    if (count == capacity) expandCapacity();
    if (index < 0 || index > count) {
        error("insert: index out of range");
    }
    for (int i = count; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    count++;
}

void Vector::erase(int index) {
    if (index < 0 || index >= count) error("remove: index out of range");
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
}

void Vector::push_back(double value) {
    insert(count, value);
}

void Vector::pop_back() {
    
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * The constructor and assignment operators follow a standard paradigm, as
 * described in the associated textbook.
 */

Vector::Vector(const Vector & src) {
    deepCopy(src);
}

Vector & Vector::operator=(const Vector & src) {
    if (this != &src) {
        if (elements != NULL) delete[] elements;
        deepCopy(src);
    }
    return *this;
}

void Vector::deepCopy(const Vector & src) {
    count = capacity = src.count;
    elements = (capacity == 0) ? NULL : new double[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = src.elements[i];
    }
}

/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This function doubles the array capacity, copies the old elements into
 * the new array, and then frees the old one.
 */

void Vector::expandCapacity() {
    capacity = max(1, capacity * 2);
    double *array = new double[capacity];
    for (int i = 0; i < count; i++) {
        array[i] = elements[i];
    }
    if (elements != NULL) delete[] elements;
    elements = array;
}

/*
 * Implementation notes: <<
 * -------------------------------
 * The insertion and extraction operators use the //template facilities in
 * strlib.h to read and write generic values in a way that treats strings
 * specially.
 */

ostream & operator<<(ostream & os, const Vector & vec) {
    os << "{";
    int len = vec.size();
    for (int i = 0; i < len; i++) {
        if (i > 0) os << ", ";
        writeGenericValue(os, vec[i], true);
    }
    return os << "}";
}