// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

bool compareInt(int a, int b){
    // shall a come before b??
    if (a > b) return true;
    return false;
}


int main(){
    int arr[] = {1 , 3, 4 , 5, 1};
    int n = 5;
    // alteast random acc
    sort(arr, arr + n, compareInt);

    // decreasing order

    for(int i = 0;  i < n; ++i){
        cout << arr[i] << endl;
    }    
}

// Movie arr;  // title, release date
// sort(arr, arr + n, compare) // release date
// sort(arr, arr + n, compare) // title