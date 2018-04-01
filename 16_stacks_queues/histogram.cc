// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void inputVec(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

void printVec(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int histogram(vector<int> heights) {
    stack<int> len, idx;
    int best = 0;
    int n = heights.size();

    for (int i = 0; i <  n; ++i) {
        int curEle = heights[i];
        int curIdx = i;
        int lastIdx = -1;
        while (!len.empty() && curEle < len.top()) {
            int area = len.top() * (curIdx - idx.top());
            best = max(best, area);
            lastIdx = idx.top();
            len.pop(); idx.pop();
        }
        curIdx = lastIdx == -1 ? curIdx : lastIdx;
        len.push(curEle);
        idx.push(curIdx);
    }

    while (!len.empty()) {
        int area = len.top() * (n - idx.top());
        best = max(best, area);
        len.pop(); idx.pop();
    }
    return best;
}

int histogram2(vector<int> heights) {
    stack<int> len, idx;
    int best = 0;
    int n = heights.size();

    for (int i = 0; i <=  n; ++i) {
        int curEle = i == n ? -1 : heights[i];
        int curIdx = i;
        int lastIdx = -1;
        while (!len.empty() && curEle < len.top()) {
            int area = len.top() * (curIdx - idx.top());
            best = max(best, area);
            lastIdx = idx.top();
            len.pop(); idx.pop();
        }

        if (i != n) {
            curIdx = lastIdx == -1 ? curIdx : lastIdx;
            len.push(curEle);
            idx.push(curIdx);
        }
    }

    return best;
}



int main() {
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    inputVec(v);

    int ans = histogram2(v);

    cout << ans << endl;
}