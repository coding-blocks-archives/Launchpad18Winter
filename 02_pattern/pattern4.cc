// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
/*
    1
   232
  34543
 4567654
567898765
*/  

    int nLines;
    cin >> nLines;

    for(int curLine = 1; curLine <= nLines; ++curLine){
        // print spaces
        int nSpaces = nLines - curLine;
        for(int i = 0; i < nSpaces; ++i){
            cout << " ";
        }

        int val;
        // print increasing order
        for(val = curLine; val <= 2 * curLine - 1; ++val){
            cout << val;
        }

        // print decreasing order
        for(val = val - 2; val >= curLine; --val){
            cout << val;
        }

        cout << endl;
    }

}