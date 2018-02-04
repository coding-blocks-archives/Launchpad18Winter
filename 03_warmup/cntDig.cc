// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    // n = 1e4;
    int cnt = 0;

    while(n != 0){
        int rem = n % 10; // getRem
        ++cnt;            // record
        n = n / 10;       // reduce the no
    }   
    cout << cnt;
}