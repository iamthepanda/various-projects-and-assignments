/* George Jone
 * 913177426
 * jone@mail.sfsu.edu
 * Netbeans Cygwin gcc
 * 02.18.2015
 * HW 1
 */
/* Problem 1
 * Reads in a paragraph of English text up to 100 words from the keyboard and stores this paragraph in a string object.
Feel free to include this task in the main() function.
 * Identifies the least frequent letter (case insensitive) in the above paragraph. Implement a separate function getLeastFreqLetter() for this task.
The main() function then calls this function to find out the least frequent letter and its frequency.
 * Calculate the frequency of each unique word (case insensitive). Implement another function countWordFreq() for this task. Use white spaces and
punctuation marks such as comma, period, semicolon and question mark as word delimiters. Please define a global struct that contains two fields,
word and its count for this task. You can then define an array of this struct to store all the unique words and its counts. The main() function will
call this function to print out each word and its corresponding frequency.
 * Identify the most frequently occurring word in the paragraph. Implement another stand-alone function getMostFreqWord() for this purpose.
This function will be called in main() to identify the most frequent word and its respective frequency.
 * Please provide a simple yet flexible user interface so other people can use & test your program.
 */

#include "newfile.h"
using namespace std;

struct words {
    int freq = 0;
    string word;
};

// gets least frequent character by going through the input and
// incrementing the counter each time the same letter is encountered
vector<char> getLeastFreqLetter(string charStr) {
    int s = 26;
    int str[s];
    
    int index = 0;
    int place = 0;
    int count = charStr.size();
    cout << charStr.size();
    vector<char> leastFreq; // returns vector of least frequent chars
    
    for (int i = 0; i < s; i++) {
        str[i] = 0;
    }
    
    for (int i = 0; i < charStr.size(); i++) {
        index = (int) (charStr[i]);
        
        if (index >= 'a' && index <= 'z') {
            str[index - 'a'] += 1;
        }
    }
    
    for (int i = 0; i < s; i++) {
        if ((count > str[i]) && (str[i] > 0)) {
            count = str[i];
            place = i;
        }
    }
    
    for (int i = 0; i < s; i++) {
        if (str[i] == count) {
            leastFreq.push_back(i + 'a');
        }
    }
    
    return leastFreq;
};

// compares words in the paragraph to see if a word is new or not
// increment frequency counter if the word is new
vector<words> countWordFreq(vector<string> strVector) {
    vector<words> wordsVector;
    
    if (!strVector.empty()) {
        words c;
        c.word = strVector[0];
        c.freq += 1;
        wordsVector.push_back(c);
        
        for (int i = 1; i < strVector.size(); i++) {
            bool isNew = true;
            
            for (int j = 0; j < wordsVector.size(); j++) {
                if (strVector[i] == wordsVector[j].word) {
                    wordsVector[j].freq += 1;
                    isNew = false;
                }
            }
            
            if (isNew) {
                c.word = strVector[i];
                c.freq = 1;
                wordsVector.push_back(c);
            }
        }
    }
    
    return wordsVector;
};

// compares words to find the most frequent
string getMostFreqWord(vector<words> intVector) {
    words mostCount = intVector[0];
    
    for (int i = 0; i < intVector.size(); i++) {
        if (mostCount.freq < intVector[i].freq) {
            mostCount = intVector[i];
        }
    }
    
    return mostCount.word;
};

// main won't work unless below the other functions
// mostly used to call vectors and set display
int main() {
    string paragraph;   // paragraph string
    vector<string> stringVector;    // used for word count
    vector<words> wordsVector;  // used for word frequency
    vector<char> least;
    char notLetter[] = {'.', ',', ';', ':', '!', '?', '`', '~', '@', '#'
            , '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+'};
    int wordCount = 0;
    
    // begin user interaction
    cout << "Type in a paragraph of up to 100 words and press [Enter]\n";
    getline(cin, paragraph);
    // transform(from beginning of paragraph, to end of paragraph
    //      , paragraph.begin()
    transform(paragraph.begin(), paragraph.end(), paragraph.begin()
            , ::tolower);    // sets input to lower case. '::' is the scope operator
    
    // finds and removes odd characters
    for (int i = 0; i < strlen(notLetter); i++) {
        paragraph.erase(remove(paragraph.begin(), paragraph.end(), notLetter[i]), paragraph.end());
    }
    
    istringstream ss(paragraph);    // streams the paragraph into word string
    while (ss) {
        string word;
        ss >> word;
        stringVector.push_back(word);
        wordCount++;
        
        if (wordCount > 100) {
            break;
        }
    }
    
    if (wordCount == 1){
        cout << "ERROR NO WORDS DETECTED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        return 0;
    }
    
    cout << "\nYou entered these words: \n";
    for (int i = 0; i < stringVector.size(); i++) {
        cout << stringVector[i] << " ";
    }
    
//    cout <<"paragraph" <<paragraph;
    least = getLeastFreqLetter(paragraph);
    cout << "\n\nLeast frequent letter: " << endl;
    for (int i = 0; i < least.size() - 1; i++) {
        cout << least[i] << ", ";
    }
    cout << least[least.size() - 1] << "\n\n";
    
    cout << "stuff\n";
    
    
    wordsVector = countWordFreq(stringVector);
    cout << setw(20) << left << "Word" << setw(25) << left << "Frequency" << endl;
    for (int i = 0; i < wordsVector.size()-1; i++) {
        cout << setw(20) << left << wordsVector[i].word;
        cout << setw(25) << left << wordsVector[i].freq << endl;
    }
    
    cout << "\n\n";
    cout << "Most frequent word: \n" << getMostFreqWord(wordsVector) << "\n\n";
    return 0;
}