// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int* foo(){
    int* x = new int;
    *x = 10;
    return x;
}

void printy(int* y){
    cout << *y;
    delete y;
}


int main(){
    int* y;
    y = foo();
    // cout << *y;
    printy(y);
    *y = 20;   
}