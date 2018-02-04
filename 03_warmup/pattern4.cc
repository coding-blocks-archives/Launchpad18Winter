// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    /*
    ABCDEEDCBA
    ABCDDCBA
    ABCCBA
    ABBA
    AA
    */

    int nLines;
    cin >> nLines;

    for(int curLine = nLines; curLine > 0; --curLine){
        char val = 'A'; 
        // inc order
        for(int i = 0; i < curLine; ++i){
            cout << val;
            val = val + 1;
        }

        // dec order
        for(int i = 0; i < curLine; ++i){
            val = val - 1;
            cout << val;
        }
        cout << endl;
    }
}