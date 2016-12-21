/*/*
 * George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans cygwin g++
 *
 * Description: recursive recursion of arrays
 */

#include "newfile.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    recursion r1;
    
    cout << "RECURSION";
    cout << "\n\nr1.askUser();\n";
    r1.askUser();
    cout << "\n\nr1.printReverse(r1.getSizeOff())\n";
    r1.printReverse(r1.getSizeOff());
    cout << "\n\nr1.findLargest(r1.getSizeOff(), 0);\n";
    r1.findLargest(r1.getSizeOff(), 0);
    cout << "\n\nr1.findK();\n";
    r1.findK(r1.getK(), 0, r1.getSizeOff());
    cout << "\n\nr1.increasingOrder();\n";
    r1.increasingOrder(0,r1.getSizeOff());
    cout << "<---sorted\n";
    
    //cout << "\n\ncout<<r1;\n";
    //cout<<r1;   
    
    cout << "\n\nr1.decreasingOrder();\n";
    r1.decreasingOrder(0,r1.getSizeOff());
    cout << "<---sorted\n";
    
    cout << "\n\ncout<<r1;\n";
    cout<<r1;           //overload the << operator
    
    return 0;
}
