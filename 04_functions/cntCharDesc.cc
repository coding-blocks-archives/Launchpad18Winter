// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool isAlphabet(char c){
    // if (c >= 'a' and c <= 'z') return true;
    // if (c >= 'A' && c <= 'Z') return true;

    // if ((c >= 'a' and c <= 'z') or (c >= 'A' && c <= 'Z')) return true;
    // if ((c >= 'a' and c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    // return false;

    return (c >= 'a' and c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

bool isWhitespace(char c){
    return c == ' ' or c == '\n' or c == '\t';
}

void printCnt(){
    int nWords = 0;
    int nLetter = 0;
    int nOthers = 0;
    int nLines = 0;
    int nSpaces = 0;
    int nDigits = 0;
    int whiteSpaces = 0;
    int nAlpha = 0;
    bool isInsideWord = false;

    while(true){
        char c = cin.get();
        if (c == '$'){
            if (isInsideWord) ++nWords;
            break;
        }

        ++nLetter;
        if (isAlphabet(c)){
            ++nAlpha;
            isInsideWord = true;
        }
        else if (isDigit(c)){
            ++nDigits;
            isInsideWord = true;
        }
        else if (isWhitespace(c)){
            ++whiteSpaces;
            if (isInsideWord == true){
                // now out of the word
                ++nWords;
            }
            isInsideWord = false;
        }
        else {
            ++nOthers;
            isInsideWord = true;
        }
    }

    cout << "words\t:" << nWords << endl;
    cout << "digits\t:" << nDigits << endl;
    cout << "letters\t:" << nLetter << endl;
    cout << "spaces\t:" << nSpaces << endl;
    cout << "whiteSpaces\t:" << whiteSpaces << endl;
    cout << "others\t:" << nOthers << endl;
    cout << "nLines\t:" << nLines << endl;
}

int main(){
    printCnt();   
}