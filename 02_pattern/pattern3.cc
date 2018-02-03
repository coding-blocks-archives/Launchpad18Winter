// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15 
*/

    int nLines;
    cin >> nLines;

    int val = 1;
    for(int curLine = 1; curLine <= nLines; ++curLine){
        int nVal = curLine;

        for(int i = 0; i < nVal; ++i){
            cout << val << " ";
            val = val + 1;  // ++val; val++;
        }
        cout << endl;   
    }


}