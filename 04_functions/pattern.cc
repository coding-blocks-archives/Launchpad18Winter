// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printStars(int n){
    for(int i = 0; i < n; ++i){
        cout << "*";
    }
}


void printPattern(int nLines){

    for(int curLine = 1; curLine <= nLines; ++curLine){
        printStars(curLine);
        cout << "_";
        printStars(nLines + 1 - curLine);
        cout << "_";
        printStars(nLines + 1 - curLine);
        cout << "_";
        printStars(curLine);
        cout << endl;
    }

}

int main(){
    int nLines; 
    cin >> nLines;
    printPattern(nLines);   
}