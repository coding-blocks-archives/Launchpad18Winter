// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int sqRoot(int num){
    int root = 0;
    while(root * root <= num){
        root = root + 1;
    }
    return root - 1;
}

int main(){
    int num ;
    cin >> num;

    int ans = sqRoot(num);
    cout << ans;   
}