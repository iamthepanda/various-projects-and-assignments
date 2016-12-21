#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

//brendan.kelly94@gmail.com
int getLeastFreqLetter(char str), countWordFreq(string txt), getMostFreqWord(string txt);

struct detail {
    char c;
    int freq;
};

int main() {
    string words;
    /*char c;
    int max[26] = {0}, min[26] = {0};
    int i = 0, index, mincount = 1000, j;
    

    printf("Enter string: ");
    fflush(stdin);
    c = getchar();*/
    
    struct detail s[26];
    char str[100];
    char c;
    int max[26] = {0}, min[26] = {0};
    int i = 0, index, mincount = 1000, j;
    //int maxcount = 1;

    for (i = 0; i < 26; i++) {
        s[i].c = i + 'a';
        s[i].freq = 0;
    }

    i = 0;
    
    
    printf("Enter string: ");

    do {
        fflush(stdin);
        c = getchar();
        str[i++] = c;
        if (c == '\n') {
            cout << c;
            break;
        } else if (!isalpha(c)) {
            cout << c;
            continue;
        }

        c = tolower(c);
        index = c - 'a';

    cout << c;
    
    getLeastFreqLetter(c);
    } while (1);
    
    cout << c;
    str[i - 1] = '\0';
    cout << c;
    //string stringValueOf = string.valueof('c');
    stringstream ss;
    ss << c;
    ss >> words;
    //getLeastFreqLetter(c);

    return 0;
}

int getLeastFreqLetter(char str){
    struct detail s[26];
    //char str[100];
    //char c;
    int max[26] = {0}, min[26] = {0};
    int i = 0, index, mincount = 1000, j;
    //int maxcount = 1;

    /*for (i = 0; i < 26; i++) {
        s[i].c = i + 'a';
        s[i].freq = 0;
    }

    i = 0;*/
    
    
    //printf("Enter string: ");

    //do {
        /*fflush(stdin);
        c = getchar();
        
        str[i++] = c;
        if (c == '\n') {
            break;
        } else if (!isalpha(c)) {
            continue;
        }

        c = tolower(c);
        index = c - 'a';

    } while (1);
    str[i - 1] = '\0';*/
    printf("The string entered is: %s\n", str);
    for (i = 0; i < 26; i++) {
        cout << s[i].freq;
        if (s[i].freq) {
            

            if (mincount >= s[i].freq) {
                if (mincount == s[i].freq) {
                    min[i] = 1;
                } else {
                    for (j = 0; j < 26; j++) {
                        min[j] = 0;
                    }

                    min[i] = 1;
                    mincount = s[i].freq;
                }
            }
        }
    }
    
    printf("\nThe least repeated characters are: ");

    for (i = 0; i < 26; i++) {
        if (min[i]) {
            printf("%c ", i + 'a');
        }
    }
    printf("\n");
/*if (maxcount < s[i].freq) {
                for (j = 0; j < 26; j++) {
                    max[j] = 0;
                }

                max[i] = 1;
                maxcount = s[i].freq;

            } else if (maxcount == s[i].freq) {
                max[i] = 1;
            }*/
    /*printf("The most repeated characters are: ");

    for (i = 0; i < 26; i++) {
        if (max[i]) {
            printf("%c ", i + 'a');
        }
    }
*/
}