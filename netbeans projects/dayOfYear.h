#ifndef _DAYOFYEAR_H
#define _DAYOFYEAR_H

#include <iostream>
using namespace std;

class DayOfYear{
      public: 
              friend bool equal(DayOfYear date1, DayOfYear date2);//a friend function that compares two objects
                                                                  //yes: if date1 is the same as date2; no: otherwise
              DayOfYear();//default constructor: 1/1/2009
              DayOfYear(int new_day, int new_month, int new_year);//
              void output() const; //
              int get_day(); // return the value of "day"
              int get_month();
              int get_year();
              void set_DayOfYear(int new_day, int new_month, int new_year); //new_day-->day, new_month->month, new_year-->year
              void set_day(int new_day); // day-->new_day
              void set_month(int new_month); 
              void set_year(int new_year); 
        
      private:
              int day;
              int month; //int --> char *
              int year;
};

#endif //
