// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printCnt(){
    int nWords = 0;
    int nLetter = 0;
    int nOthers = 0;
    int nLines = 0;
    int nSpaces = 0;
    int nDigits = 0;
    int whiteSpaces = 0;
    int nAlpha = 0;

    while(true){
        char c = cin.get();
        if (c == '$'){
            break;
        }

        ++letters;
        if (isAlphabet(c)){
            ++nAlpha;
        }
        else if (isDigit(c)){
            ++nDigits;
        }
        else if (isWhitespace(c)){
            ++whiteSpaces;
        }
        else {
            ++nOthers;
        }
    }

    cout << "words\t:" << nWords << endl;
    cout << "digits\t:" << nDigits << endl;
    cout << "letters\t:" << nLetter << endl;
    cout << "spaces\t:" << nSpaces << endl;
    cout << "others\t:" << nOthers << endl;
    cout << "nLines\t:" << nLines << endl;
}

int main(){
    printCnt();   
}