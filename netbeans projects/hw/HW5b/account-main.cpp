/* 
 * File:   account-main.cpp
 * Author: George Jone
 * ID: 913177426
 * Compiler: GNU Cygwin g++
 *
 * Created on April 6, 2015, 10:35 AM
 */

#include <string>
#include "account.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() // Sample code to test the getProductID function
{
    Account acc;
    double d, w;
    cout<<"How much do you want to deposit?";
    
    cin>> d;
    
    try {
        cout << acc.deposit(d) << endl;
    } catch (Exception_Negative_Deposit negDep) {
        cout << negDep.what();
    }
    
    cout<<"How much do you want to withdraw?";
    
    cin>> w;
    
    try {
        cout << acc.withdraw(w) << endl;
    } catch (Exception_Overdraw over) {
        cout << over.what();
    } catch (Exception_Negative_Withdraw negWith) {
        cout << negWith.what();
    }
    
    return 0;
}