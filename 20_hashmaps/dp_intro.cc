// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int memo[100];

long long fib(int n) {
    if (n <= 1) return n;

    if (memo[n] != -1){
        return memo[n];
    }

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

long long fib2(int n){
    long long dp[100];

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n; cin >> n;

    for(int i = 0; i < 100; ++i){
        memo[i] = -1;
    }

    cout << fib2(n);
}