// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    /*
         *
        ***
       *****
        ***
         *
    */
    int nLines;
    cin >> nLines;

    // print n/2+1 in inc
    int incLines = nLines / 2 + 1;
    for(int curLine = 1; curLine <= incLines; ++curLine){
        // print spaces
        int nSpace = incLines - curLine;
        for(int i = 0; i < nSpace; ++i){
            cout << " ";
        }

        // print star
        for(int i = 0; i < 2 * curLine - 1; ++i){
            cout << "*";
        }

        cout << endl;
    }

    // print n - n/2+1 in dec
    int remLines = nLines - incLines;
    for(int curLine = 1; curLine <= remLines; ++curLine){
        // print Spaces
        for(int i = 0; i < curLine; ++i){
            cout << " ";
        }

        // print stars
        int nStars = nLines - 2 * curLine;
        for(int i = 0; i < nStars; ++i){
            cout << "*";
        }
        cout << endl;
    }
}