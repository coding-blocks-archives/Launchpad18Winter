// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int reduceNo(int n, vector<int>& memo) {
    if (n <= 1) {
        return 0;
    }

    if (memo[n] != -1) return memo[n];

    const int inf = (int)1e6;
    int q1 = inf, q2 = inf, q3 = inf;

    if (n % 3 == 0) {
        q1 = reduceNo(n / 3, memo) + 1;
    }

    if (n % 2 == 0) {
        q2 = reduceNo(n / 2, memo) + 1;
    }

    q3 = reduceNo(n - 1, memo) + 1;
    return memo[n] = min(q1, min(q2, q3));
}

int reduceNo1(int n) {
    vector<int> dp(n + 10);
    int inf = (int)1e6;
    for (int i = 0; i <= n; ++i) dp[i] = inf;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int curNo = 4; curNo <= n; ++curNo) {
        if (curNo % 3 == 0) dp[curNo] = dp[curNo / 3] + 1;
        if (curNo % 2 == 0) dp[curNo] = min(dp[curNo] , dp[curNo / 2] + 1);
        dp[curNo] = min(dp[curNo], dp[curNo - 1] + 1);
    }
    return dp[n];
}


int main() {
    int n;
    cin >> n;
    vector<int> memo(n+1, -1);
    int ans = reduceNo(n, memo);
    cout << ans;
}