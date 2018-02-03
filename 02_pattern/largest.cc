#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int inf = 1e6;
    int largest = -inf;
    
    for(int i = 0; i < n; ++i){
        int curNum;
        cin >> curNum;
        // check for which is better
        if (curNum > largest){
            largest = curNum;
        }
    }
    cout << largest;
}