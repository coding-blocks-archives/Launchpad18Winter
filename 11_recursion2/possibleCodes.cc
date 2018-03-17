// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

char digToChar(int num){
    // 1-->a
    // 2-->b
    // 'a' + num - 1;
    return 'a' + num - 1;
}

void printCodes(char inp[], int be, char ansSoFar[], int i) {
    if (inp[be] == '\0'){
        ansSoFar[i] = '\0';
        cout << ansSoFar << endl;
        return;
    }

    //123
    int num = inp[be] - '0';                    // 1
    char curChar = digToChar(num);              // a
    ansSoFar[i] = curChar;
    printCodes(inp, be + 1, ansSoFar, i + 1);   // abc, aw

    if (inp[be + 1] == '\0') return;            // no more next char

    // 12 3
    int nextDig = inp[be + 1] - '0';            // 2
    num = num * 10 + nextDig;                   // 1 * 10 + 2
    if (num <= 26) {
        ansSoFar[i] = digToChar(num);
        printCodes(inp, be + 2, ansSoFar, i + 1);
    }
}


int main() {
    char arr[100], ans[100];
    cin >> arr;
    printCodes(arr, 0, ans, 0);
}