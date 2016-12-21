#ifndef vector_h
#define vector_h

#include <iostream>

/* This class stores an ordered list of values similar to an array.  It
 * supports traditional array selection using square brackets, but also
 * supports inserting and deleting elements.
 */

class Vector {
private:

    /*
     * Implementation notes: Vector data structure
     * -------------------------------------------
     * The elements of the Vector are stored in a dynamic array of the
     * specified element type.  If the space in the array is ever exhausted,
     * the implementation doubles the array capacity.
     */

    double *elements; /* A dynamic array of the elements   */
    int capacity; /* The allocated size of the array   */
    int count; /* The number of elements in use     */
    int max;

public:
    void expandCapacity();
    void deepCopy(const Vector & src);

    // Constructor Initializes a new vector
    Vector();   //Usage: Vector vec; creates an empty vector.  
    Vector(int n, double value = double());    //Vector vec(n, value); creates an array with n elements, each of which is initialized to value; if value is missing, the elements are initialized to the default value for the type.
    ~Vector(); // Destructor: ~Vector Frees any heap storage allocated by this vector.
    int size() const; //Usage: int nElems = vec.size(); Returns the number of elements in this vector.
    bool isEmpty() const; //Usage: if (vec.isEmpty()) Returns true if this vector contains no elements.
    void clear(); //Usage: vec.clear(); Removes all elements from this vector.

    /* Usage: double val = vec.get(index);
     * Returns the element at the specified index in this vector.  This method
     * signals an error if the index is not in the array range.
     */

    const double & get(int index) const;

    /*
     * Method: set
     * Usage: vec.set(index, value);
     * -----------------------------
     * Replaces the element at the specified index in this vector with a new
     * value.  The previous value at that index is overwritten.  This method
     * signals an error if the index is not in the array range.
     */

    void set(int index, const double & value);

    /*
     * Method: insert
     * Usage: vec.insert(0, value);
     * ----------------------------
     * Inserts the element into this vector before the specified index.  All
     * subsequent elements are shifted one position to the right.  This method
     * signals an error if the index is outside the range from 0 up to and
     * including the length of the vector.
     */

    void insert(int index, double value);

    /*
     * Method: remove
     * Usage: vec.remove(index);
     * -------------------------
     * Removes the element at the specified index from this vector.  All
     * subsequent elements are shifted one position to the left.  This method
     * signals an error if the index is outside the array range.
     */

    void erase(int index);
    void push_back(double value); //Usage: vec.push_back(value); Adds a new value to the end of this vector.
    void pop_back();
    
    /*
     * Additional Vector operations
     * ----------------------------
     * In addition to the methods listed in this interface, the Vector class
     * supports the following operations:
     *
     *   - Stream I/O using the << and >> operators
     *   - Deep copying for the copy constructor and assignment operator
     *   - Iteration using the range-based for statement or STL iterators
     *
     * The iteration forms process the Vector in index order.
     */

    /* Private section */

    /**********************************************************************/
    /* Note: Everything below this point in the file is logically part    */
    /* of the implementation and should not be of interest to clients.    */
    /**********************************************************************/

    /*
     * Hidden feature
     * ---------------
     * The remainder of this file consists of the code required to support deep
     * copying. Including these methods in the public interface
     * would make that interface more difficult to understand for the average
     * client.
     *
     * Deep copying support
     * --------------------
     * This copy constructor and operator= are defined to make a deep copy,
     * making it possible to pass or return vectors by value and assign from
     * one vector to another.
     */

    Vector(const Vector & src);
    Vector & operator=(const Vector & src);
};

#endif