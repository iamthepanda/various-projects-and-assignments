/* George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans Cygwin gcc
 * 02.26.2015
 * HW 2 File Merge
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void merging(string a, string b) {
    ifstream Instream1, Instream2; //string of input
    ofstream Outstream;
    Instream1.open(a.c_str());
    Instream2.open(b.c_str());
    Outstream.open("file3.txt");

    int file1, file2;
    bool NumIn1 = true; // true if not end of file
    bool NumIn2 = true;
    Instream1>>file1;
    Instream2>>file2;

    do {
        if (file1 < file2) // compare rows
        {
            Outstream << file1 << endl;
            if (!Instream1.eof())
                Instream1 >> file1;
            else {
                file1 = 2147483647; // large number
                NumIn1 = false;
            }
        }
        else if (file2 < file1) // compare reverse case
        {
            Outstream << file2 << endl;
            if (!Instream2.eof())
                Instream2 >> file2;
            else {
                file2 = 2147483647;
                NumIn2 = false;
            }
        }
        else if (file1 == file2)// third case
        {
            // outstream smaller number
            Outstream << file1 << endl << file2 << endl;
            if (!Instream1.eof())
                Instream1 >> file1;
            else {
                file1 = 2147483647; // assigns the number as max to never outstream
                NumIn1 = false;
            }
            if (!Instream2.eof())
                Instream2 >> file2;
            else {
                file2 = 2147483647;
                NumIn2 = false;
            }

        }
    } while ((NumIn1 || NumIn2)); // stop loop

    cout << "the output file is called file3.txt" << endl;
}

int main(int argc, char** argv) {
    string a, b;

    cout << "Enter the file1 file name" << endl;
    cin >> a;

    cout << "Enter the file2 file name" << endl;
    cin >> b;

    merging(a, b);

    return 0;
}