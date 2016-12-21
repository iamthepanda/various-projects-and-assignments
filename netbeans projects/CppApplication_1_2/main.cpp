/* 
 * File:   main.cpp
 * Author: george
 *
 * Created on August 31, 2015, 2:15 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */

void square() {
    int number = 0;

    cout << "square()" << endl;

    cout << "Please enter a number: ";
    cin >> number;

    cout << "The square of that number is " << (number * number) << endl;
}

void assign() {
    int x = 10, y = 20;

    cout << "assign()" << endl;
    cout << "does x=0?" << endl;

    if (x == 0) {
        cout << "true!" << endl;
    } else {
        cout << "false!" << endl;
    }

    cout << "x = " << x << endl;
}

void out_of_bounds() {
    int x[10];
    int c = 127;
    int y[10];

    cout << "out_of_bounds()" << endl;

    for (int i = 0; i < 10; i++) {
        x[i] = i;
        y[i] = i;
    }

    cout << y[8] << endl;
    cout << y[9] << endl;
    cout << y[10] << endl;

    cout << c << endl;

    cout << x[8] << endl;
    cout << x[9] << endl;
    cout << x[10] << endl;

    cout << &c << endl;
    cout << &y[10] << endl;
}

void pointer() {
    int x = 16;
    int* y = &x;

    cout << "pointer()" << endl;

    cout << x << endl;
    cout << y << endl;
    cout << *y << endl;
}

int main(int argc, char** argv) {
    square();
    cout << endl;
    assign();
    cout << endl;
    out_of_bounds();
    cout << endl;
    pointer();

    return 0;
}