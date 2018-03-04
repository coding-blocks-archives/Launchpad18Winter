// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n){
    // recursion
    if (n <= 0){
        return 1;
    }

    int smallFactorial = fact(n - 1); // always work
    int ans = n * smallFactorial;
    return ans;
}

int fib(int n){
    // fib returns the nth fibonacci number
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
}


int main(){
    int n;
    cin >> n;

    // int ans = fact(n);
    // cout << ans;    

    int ans = fib(n);
    cout << ans;
}