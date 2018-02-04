// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int tenPower = 1;
    while(n >= tenPower){
        ++cnt;
        tenPower = tenPower * 10;
    }   

    cout << tenPower << endl;
    cout << cnt;
}