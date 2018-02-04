// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
/*
    5
    5 4
    5 4 3
    5 4 3 2
    5 4 3 2 1 
*/
    int nLines;
    cin >> nLines;
    for(int curLine = 1; curLine <= nLines; ++curLine){
        // print val
        int val = nLines;
        for(int i = 1; i <= curLine; ++i){
            cout << val;
            val--;
        }
        cout << endl;
    }
}