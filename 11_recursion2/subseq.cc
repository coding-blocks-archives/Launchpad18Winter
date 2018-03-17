// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void subseq(char inp[], int be, char ans[], int i){
    if (inp[be] == '\0'){
        ans[i] = '\0';
        cout << ans << endl;
        return;
    }

    subseq(inp, be + 1, ans, i);
    ans[i] = inp[be];
    subseq(inp, be + 1, ans, i + 1); 
}

int main(){
    char str[100], ans[100];
    cin >> str;
    subseq(str, 0, ans, 0);   
}