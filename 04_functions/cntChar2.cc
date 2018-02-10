// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntChar(){
    char c;
    int cnt = 0;

    while(true){
        c = cin.get();
        if (c == '$'){
            break;
        }

        // its confirmed that char is not a $
        ++cnt;
    }
    return cnt;
}



int main(){
    int ans = cntChar();
    cout << ans;   
}