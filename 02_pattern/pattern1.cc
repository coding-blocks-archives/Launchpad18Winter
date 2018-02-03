// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {

    /*
        1
        12
        123
    */

    int nLines;
    cin >> nLines;

    for (int curLine = 1; curLine <= nLines; ++curLine) {
        // think about just one line
        // think about 3rd line
        for (int val = 1; val <= curLine; ++val) {
            cout << val << " ";
            cout << endl;
        }
    }

}