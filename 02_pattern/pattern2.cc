// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){   
/*
    1
   123
  12345
 1234567
123456789
*/

    int nLines;
    cin >> nLines;

    for(int curLine = 1; curLine <= nLines; ++curLine){
        // print spaces
        int nSpaces = nLines - curLine;
        for(int curSpace = 1; curSpace <= nSpaces; ++curSpace){
            cout << " ";
        }

        // print values
        int nVals = 2 * curLine - 1;
        for(int val = 1; val <= nVals; ++val){
            cout << val;
        }

        // print enter
        cout << endl;
    }

}