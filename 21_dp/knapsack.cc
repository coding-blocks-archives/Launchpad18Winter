// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[100][100];
int noOfFuncCall = 0;

void input(vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int knapsack(vector<int>& val, vector<int>& wt, int n, int idx, int capacity) {
    ++noOfFuncCall;

    if (n == idx) {
        return 0;
    }
    if (dp[idx][capacity] != -1) return dp[idx][capacity];

    int q1 = 0, q2 = 0;
    if (wt[idx] <= capacity) {
        q1 = val[idx] + knapsack(val, wt, n, idx + 1, capacity - wt[idx]);
    }

    q2 = knapsack(val, wt, n, idx + 1, capacity);
    return dp[idx][capacity] = max(q1, q2);

}

void print(int dp[100][100], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j] << " " ;
        }
        cout << endl;
    }
}

int knapsackdp(vector<int>& val, vector<int>& wt, int n, int capacity) {
    int dp[100][100] = {};      // 99 * 99

    for (int itemNo = 1; itemNo <= n; ++itemNo) {
        for (int c = 1; c <= capacity; ++c) {
            int q1 = 0, q2 = 0;
            if (c <= wt[itemNo - 1]) {
                q1 = val[itemNo - 1] + dp[itemNo - 1][c - wt[itemNo - 1]];
            }
            q2 = dp[itemNo - 1][c];
            dp[itemNo][c] = max(q1, q2);
        }
    }
    print(dp, n + 1, capacity +1);
    return dp[n][capacity];
}

int main() {
    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> wt(n);
    input(val, n);
    input(wt, n);

    memset(dp, -1, sizeof dp);

    int capacity;
    cin >> capacity;

    // int ans = knapsack(val , wt, n, 0, capacity);
    int ans = knapsackdp(val , wt, n, capacity);
    cout << ans << " " << noOfFuncCall;
}