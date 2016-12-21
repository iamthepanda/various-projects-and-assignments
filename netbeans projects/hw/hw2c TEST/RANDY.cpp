#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void random_access();

int main() {
    random_access();
    return 0;
}

/*void random_access() {
    cout << "\nAccessing File...\n";
    fstream file("file1.txt", fstream::app);
    if (file.is_open()) {
        cout << "\nInserting numbers at line 0000...\n";
        for (int i = 81; i >= 77; i--) {
            file << "77" << i << "\n";
        }
        file.close();
        file.open("file1.txt");
        file.seekg(-25, ios::end);
        char * numbers = new char(25);
        file.read(numbers, 25);
        for (int j = 0; j < 4000; j++) {
            file.seekg((-30 - (j * 5)), ios::end);
            string line;
            getline(file, line);
            file.seekp((-5 - (j * 5)), ios::end);
            file << line << "\n";
        }
        file.seekp(30000, ios::beg);
        file << numbers;
        file.close();
        delete numbers;
    } else {
        cout << "file1.txt is could not be opened";
    }
}*/

void random_access() {
    cout << "\nAccessing File...\n";
    fstream file("file1.txt", fstream::app);
    if (file.is_open()) {
        cout << "\nInserting numbers at line 0000...\n";
        for (int i = 77; i <= 81; i++) {
            file << "77" << i << "\n";
        }
        file.close();
        file.open("file1.txt");
        file.seekg(-25, ios::end);
        char * numbers = new char(25);
        file.read(numbers, 25);
        for (int j = 0; j < 10; j++) {
            file.seekg((-30 - (j * 5)), ios::end);
            string line;
            getline(file, line);
            file.seekp((-5 - (j * 5)), ios::end);
            file << line << "\n";
        }
        file.seekp(10, ios::beg);
        file << numbers;
        file.close();
        delete numbers;
    } else {
        cout << "file1.txt is could not be opened";
    }
}