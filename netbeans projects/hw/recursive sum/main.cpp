/* 
 * File:   main.cpp
 * Author: george
 *
 * Created on May 16, 2015, 2:35 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int sum(int arr, int size);

int sum(int *arr, int size) {
    if (size == 0) {
        return 0;
    } else {
        int result = *arr + sum(arr+1, size-1);
        cout << "cout << result << endl;" << endl;
        cout << result << endl;
        return result;
    }
}

int main(int argc, char** argv) {
    int set [4] = {1, 2, 3, 4};
    int *arr = set;
    int size = 4;
    
    cout << "cout << sum(arr, size);" << endl;
        cout << sum(arr, size) << endl;
    return 0;
}