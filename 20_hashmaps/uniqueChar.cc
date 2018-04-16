// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
using namespace std;

void printUnqiue(string s){
    map<char, int> m;

    for(int i = 0; i < s.size(); ++i){
        char curChar = s[i];
        ++m[curChar];
    }

    for(int i = 0; i < s.size(); ++i){
        if (m[s[i]] == 1){
            cout << s[i] << " ";
        }
    }
}


int main(){
    string s;
    cin >> s;

    printUnqiue(s);    
}