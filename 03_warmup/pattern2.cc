// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
/*
    5
    4 4
    3 3 3
    2 2 2 2
    1 1 1 1 1
*/
    int nLines;
    cin >> nLines;
    for(int curLine = 1; curLine <= nLines; ++curLine){
        int val = nLines - curLine + 1;

        for(int i = 1; i <= curLine; ++i){
            cout << val;
        }
        cout << endl;
    }

}