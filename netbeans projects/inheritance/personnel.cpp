/*
  Name: personnel.cpp
  Copyright: 
  Author: 
  Date: 22/02/09 15:02
  Description: manage a personnel database that currently consists of one employee Mary
 */

#include "dayOfYear.h"
#include "person.h"
#include "Employee.h"

int main() {
    DayOfYear date(20, 7, 1985);

//    Person mary_p(101, "Mary", date);
    Employee mary_s, mary_c;
    
    Employee mary_p(101, "Mary", date);
    // Person & mary_p = mary_s;

    Person & person1 = mary_s;

    mary_s.output(); //student verion

    mary_p.output();

    print(mary_s);

    mary_s.setBase(2);
    mary_s.setRate(1, .08);
    mary_s.setRate(2, .12);

    mary_c = mary_s;

    cout << mary_s;
    cout << mary_c;
//    --------------------------------------------------
    
    
    
    
    

    return 0;
}