// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
 /*
    1*2*3*10*11*12
      4*5*8*9
        6*7
 */   

    int nLines;
    cin >> nLines;
    int prevBegVal = nLines * (nLines + 1) + 1;
    int simpleVal = 1;

    for (int curLine = nLines; curLine > 0; --curLine){
        int nSpace = nLines - curLine;
        for(int i = 0; i < nSpace; ++i){
            cout << "  ";
        }


        // print simple inc order
        for(int i = 0; i < curLine; ++i){
            cout << simpleVal;
            cout << "*";
            ++simpleVal;
        }

        // print complex inc order
        int curEndVal  = prevBegVal - 1;
        int curStartVal = curEndVal - curLine + 1;
        prevBegVal = curStartVal;   // for the next iteration

        for(int i = 0; i < curLine; ++i){
            cout << curStartVal;
            if (curStartVal != curEndVal){
                cout << "*";
            }
            ++curStartVal;
        }
        cout << endl;
    }
}