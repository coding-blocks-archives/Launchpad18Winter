// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int curNum = 2; curNum <= n; ++curNum){
        
        int div = 2;
        bool isCurNumPrime = true;      // assumption..flag
        while(div < curNum){
            if (curNum % div == 0){
                isCurNumPrime = false;
                break;
            }
            div = div + 1;
        }

        if (isCurNumPrime){
            cout << curNum << " ";
        }
    }   
}