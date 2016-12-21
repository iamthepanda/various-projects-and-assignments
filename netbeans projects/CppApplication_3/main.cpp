/* 
 * File:   main.cpp
 * Author: george
 *
 * Created on October 5, 2015, 10:10 AM
 */

#include <iostream>
#include <math.h>

using namespace std;

int binarySearch(int a[], int x, int i, int low, int high) {
    if(low>high)
        return false;
    int Mid = (low + high) / 2;
    Mid = ceil(Mid);
    if (x > a[Mid])
        return binarySearch(a, x, i, Mid + 1, high);
    else if (x < a[Mid])
        return binarySearch(a, x, i, low, Mid - 1);
    else
        return Mid;
}

//int bs(int a[], int n, int x) {
////    int mid;
//    int lbound = 0;
//    int ubound = n - 1;
//
//    for (int i = 0; i < n; i++)
//        return binarySearch(a, x, lbound, ubound);
//    return false;
//}

int main(int argc, char const *argv[]) {
    const int n = 9;
    const int K = 7;
    const int x = 5;
    int a[n];
    for (int i; i < n; i++)
        a[i] = i;
    for (int j = 0; j < K; j++)
        for (int i = 0; i < n; i++)
            if (binarySearch(a, n, i, 0, n) != i)
                cout << "\nERROR";
    return 0;
}