// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void inputVec(vector<int>& v){
    for(int i = 0; i < v.size(); ++i){
        cin >> v[i];
    }
}

void printVec(vector<int>& v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> prevSmaller(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;

    for(int i = 0; i < arr.size(); ++i){
        int cur = arr[i];
        while(s.empty() == false && cur < s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }
        else {
            ans[i] = s.top();
        }
        s.push(cur);
    }
    return ans;
}

int main(){
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    inputVec(v);

    vector<int> ans = prevSmaller(v);

    printVec(ans);   
}