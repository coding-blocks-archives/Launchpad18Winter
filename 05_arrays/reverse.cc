// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


int reverseNum(int n){
    int ans = 0;
    while(n != 0){
        int curDig = n % 10;
        ans = ans * 10;
        ans = ans + curDig;
        n = n / 10; 
    }
    return ans;
}


int main(){
    int num;
    cin >> num;

    int ans = reverseNum(num);
    cout << ans;   
}