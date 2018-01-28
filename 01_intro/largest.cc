// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b){
        if (a > c){
            cout << a << "is largest";
        }
        else {
            cout << c << "is largest";
        }
    }
    else {
        // either b or c
        if (b > c){
            cout << b << "is largest";
        }
        else {
            cout << c << " is largest";
        }
    }   
}