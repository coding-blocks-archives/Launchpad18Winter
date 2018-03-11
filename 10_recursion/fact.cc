#include <iostream>
using namespace std;

int fact(int n){
    if (n <= 0) return 1;

    int smallAns = fact(n - 1); // recurrence relation
    int ans = n * smallAns;     // n * (n-1)!
    return ans;
}

const int inf = 1e6;
int numSteps(int n){
    if (n < 0) return inf;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 1;

    int ans1 = numSteps(n - 1);
    int ans2 = numSteps(n - 2);
    int ans3 = numSteps(n - 3);
    return min(ans1, min(ans2, ans3)) + 1;
}

int main(){
    // int n;
    // cin >> n;
    // int ans = fact(n);      // ans = n!
    // cout << ans;

    int n;
    cin >> n;
    int ans = numSteps(n);
    cout << ans;
}