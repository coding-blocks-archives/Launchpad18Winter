// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int nLines;
    cin >> nLines;

    for (int curLine = 1; curLine <= nLines; ++curLine) {
        // int val = 1;
        // if (curLine % 2 == 0) {
        //     val = 0;
        // }
        
        int val = curLine % 2;

        for (int i = 0; i < curLine; ++i) {
            cout << val << " ";
            // if (val == 0) {
            //     val = 1;
            // } else {
            //     val = 0;
            // }
            // val = (val == 0) ? 1 : 0;
            val = 1 - val;
        }
        cout << endl;
    }
}