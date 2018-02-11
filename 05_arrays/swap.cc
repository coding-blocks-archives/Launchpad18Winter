// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int& x, int& y){
    // cout << y << " " << x;
    int tmp = x;
    x = y;
    y = tmp;
}


int main(){
    int a, b;
    cin >> a >> b;

    mySwap(a, b);
    cout << a << " " << b;

}