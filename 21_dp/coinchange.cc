// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
const int inf = 1e7;
using namespace std;

int dp[1000000] = {0};

int minCoins(vector<int>& coins, int n, int total) {
    if (total == 0) return 0;   
    if (dp[total] != 0) return dp[total];

    int ans = 1e7;

    for (int i = 0; i < n; ++i) {
        int curCoin = coins[i];
        if (curCoin <= total){
            int q1 = minCoins(coins, n, total - curCoin) + 1;
            ans = min(ans, q1);
        }
    }
    return dp[total] = ans;
}

int minCoins1(vector<int>& coins, int n, int total){
    int* dp = new int[total + 10]{};

    for(int curTotal = 1; curTotal <= total; ++curTotal){
        int best = inf;
        for(int i = 0; i < n; ++i){
            int curCoin = coins[i];
            if (curCoin <= curTotal){
                best = min(best, 1 + dp[curTotal - curCoin]);
            }
        }
        dp[curTotal] = best;
    }
    // delete dp dynamic array
    return dp[total];

}


int main() {
    int n;
    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int total; cin >> total;
    int ans = minCoins1(coins, n, total);

    cout << ans;
}