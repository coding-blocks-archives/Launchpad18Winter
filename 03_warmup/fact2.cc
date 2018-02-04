// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

// how the machine looks like??
// how the function looks like ??
int factorial(int n);

int main(){
    int n, r;
    cin >> n >> r;

    int nFact = factorial(n);
    int rFact = factorial(r);
    int n_rFact = factorial(n - r);

    int ncr = nFact / rFact / n_rFact;
}

int factorial(int n){
    // I have n
    int ans = 1;
    for(int x = 1; x <= n; ++x){
        ans = ans * x;
    }
    return ans;
}