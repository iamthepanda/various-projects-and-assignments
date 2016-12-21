/* 
 * File:   Employee.h
 * Author: george
 *
 * Created on May 12, 2015, 3:03 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <vector>
#include "person.h"
#include "dayOfYear.h"

class Employee : public Person {
public:
    //         a default constructor
    Employee(); //default: 1->level, 0->num_grades, NULL->grades

    //         Employee(int new_id, string new_name, DayOfYear date, int lvl ); //lvl->level, 0->num_grades, NULL->grades

    //the big-3
    ~Employee(); //destructor
    Employee(const Employee& std); //copy constructor: std -->*this
    void operator=(const Employee& rhs); //rhs --> *this 

    //an accessor and 
    //          employment date 
    const DayOfYear getDate() const;
    //current annual salary
    double getAnnual() const;
    //base salary
    double getBase() const;
    //a dynamic array to keep track of the annual salary increase rate since the year of employment. For instance, an employee might have a 10%, 15%, and 12% increases in the past three years. This dynamic array will hold the following three numbers: 0.1, 0.15, and 0.12. 
    double getRate(int a) const;
    
    //mutator for each of the above data members
    //          employment date 
    void setDate(DayOfYear someDate);
    //current annual salary
    void setAnnual(double b);
    //base salary
    void setBase(int b);
    //a dynamic array to keep track of the annual salary increase rate since the year of employment. For instance, an employee might have a 10%, 15%, and 12% increases in the past three years. This dynamic array will hold the following three numbers: 0.1, 0.15, and 0.12. 
    void setRate(int a, double b);

    //an overloaded put operator (<<) to print out all the information in an Employee object
    friend ostream & operator<<(ostream & out, const Employee& std);
    
    //redefine the output() function in the base class.
    virtual void output() const; //print out a student's info.
    
private:
    //          employment date 
    DayOfYear date;
    //current annual salary
    double annual;
    //base salary
    double base;
    //a dynamic array to keep track of the annual salary increase rate since the year of employment. For instance, an employee might have a 10%, 15%, and 12% increases in the past three years. This dynamic array will hold the following three numbers: 0.1, 0.15, and 0.12. 
    int numRate;
    double *rate;
};

#endif //EMPLOYEE_H