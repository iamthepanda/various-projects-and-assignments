//File name--student.cpp: implementation file for the Employee class
#include "Employee.h"

//destructor

Employee::~Employee() {
    if (rate != NULL) {
        delete [] rate;
    }
}

//default constructor
Employee::Employee() : Person() {
    //call the constructor of the base class to initialize the inherited members
    annual = 1;
    numRate = 0;
    rate = NULL;
}

//a second constructor

Employee::Employee(int new_id, string new_name, DayOfYear date, int lvl) : Person(new_id, new_name, date), annual(lvl), numRate(0), rate(NULL) {
    //call the corresponding constructor in the 
    //base class to initialize the inherited members
    /*  annual = lvl;
      numRate = 0;
      rate = NULL;   
     */
}

//copy constructor

Employee::Employee(const Employee & std) : Person(std) //call the copy constructor of the base class
{
    annual = std.annual;
    numRate = std.numRate;
    if (numRate <= 0)
        rate = NULL;
    else { //allocate space to *rate and copy the rate from std
        (*this).rate = new double [ numRate ];
        if (rate == NULL) {
            cerr << "Employee:Employee(const Employee &): Memory allocation error\n";
            exit(-1);
        }
        for (int i = 0; i < numRate; i++)
            rate[ i ] = std.rate[ i ];
    }
}

void Employee::operator=(const Employee & rhs) {
    (*this).Person::operator=(rhs);
    annual = rhs.annual;
    if (numRate != rhs.numRate) {
        delete [] rate;
        numRate = rhs.numRate;
        rate = new double[ numRate ];
        if (rate == NULL) {
            cerr << "Employee:operator=(const Employee &): Memory allocation error\n";
            exit(-1);
        }
        for (int i = 0; i < numRate; i++)
            rate[ i ] = rhs.rate[ i ];
    }
}

double Employee::getAnnual() const {
    return annual;
}

double Employee::getBase() const {
    return numRate;
}

double Employee::getRate(int i) const {
    if (i < 1 || i > numRate)
        return -1.0; //non-existent rate
    else
        return rate[ i - 1 ];
}

void Employee::setAnnual(double lvl) {
    annual = lvl;
}

void Employee::setBase(int num) {
    numRate = num;
    if (num > 0) {
        rate = new double [ num ];
        if (rate == NULL) {
            cerr << "Employee:set_numRate(int ): Memory allocation error\n";
            exit(-1);
        }
        for (int i = 0; i < num; i++)
            rate[ i ] = 0;
    }
}

void Employee::setRate(int i, double grd) {
    if (i >= 1 && i <= numRate)
        rate[ i - 1 ] = grd;
}

ostream& operator<<(ostream& out, const Employee& std) {
    DayOfYear hireDay;
    hireDay = std.getDate();

    out << "------------------------------\n";
    out << "id=" << std.get_id() << endl;
    out << "name=" << std.get_name() << endl;
    out << "hire day=" << hireDay.get_day();
    out << "-" << hireDay.get_month();
    out << "-" << hireDay.get_year() << endl;
    out << "annual=" << std.annual << endl;
    out << "#rate=" << std.numRate << endl;
    for (int i = 1; i <= std.numRate; i++)
        out << "rate[" << i << "]=" << std.rate[i - 1] << " ";
    out << endl;
    out << "------------------------------\n";

    return out;
}

void Employee::output() const {
    DayOfYear hireDay;
    hireDay = getDate();

    cout << "------------------------------\n";
    cout << "id=" << get_id() << endl;
    cout << "name=" << get_name() << endl; //private-is-private rule 
    cout << "hire day=" << hireDay.get_day();
    cout << "-" << hireDay.get_month();
    cout << "-" << hireDay.get_year() << endl;
    cout << "annual=" << annual << endl;
    cout << "#rate=" << numRate << endl;
    for (int i = 1; i <= numRate; i++)
        cout << "rate[" << i << "]=" << rate[i - 1] << " ";
    cout << endl;
    cout << "------------------------------\n";
}

const DayOfYear Employee::getDate() const{
    return date;
}