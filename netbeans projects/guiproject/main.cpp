// Colored Blocks.cpp : main project file.

//#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
//#include <sys/select.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

void WaitKey();

int main() {

    int len = 0, x, y;
    time_t t;
    srand((unsigned) time(&t)); // randomize using the time

    cout << endl << endl << endl << "\t\t\t"; // start 3 down, 3 tabs, right
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 10; y++) {
            SetConsoleTextAttribute(console, (rand() % 16)*15); // set color for the next print
            cout << " ";
        }
        SetConsoleTextAttribute(console, 0); // set color to black background
        cout << endl << "\t\t\t"; // Start next line, 1 down, 3 tabs over
    }
    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
    WaitKey(); // Program over, wait for a keypress to close program
}



int kbhit(void) {
    struct timeval tv;
    fd_set read_fd;

    /* Do not wait at all, not even a microsecond */
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    /* Must be done first to initialize read_fd */
    FD_ZERO(&read_fd);

    /* Makes select() ask if input is ready:
     * 0 is the file descriptor for stdin */
    FD_SET(0, &read_fd);

    /* The first parameter is the number of the
     * largest file descriptor to check + 1. */
    if (select(1, &read_fd, NULL, /*No writes*/NULL, /*No exceptions*/&tv) == -1)
        return 0; /* An error occured */

    /* read_fd now holds a bit map of files that are
     * readable. We test the entry for the standard
     * input (file 0). */

    if (FD_ISSET(0, &read_fd))
        /* Character pending on stdin */
        return 1;

    /* no characters were pending */
    return 0;
}


void WaitKey() {
    cout << endl << endl << endl << "\t\t\tPress any key";
    while (kbhit()) cin.get(); // Empty the input buffer
    cin.get(); // Wait for a key
    while (kbhit()) cin.get(); // Empty the input buffer (some keys sends two messages)*/
}
