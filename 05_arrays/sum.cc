// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int sumArr(int arr[4], int& hathi){
    int sum = 0;
    // arr[0] = 1000;
    // hathi = 1;
    for(int i = 0; i < hathi; ++i){
        sum = sum + arr[i];
    }
    return sum;
}

int searchElement(int arr[], int n, int x){
    for(int i = 0; i < n; ++i){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[10];    // aware : dim has to be a compile time const
    int n;      
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }   

    // int sum = sumArr(arr, n);
    // cout << sum;

    // cout << arr[0] << endl;
    // cout << n;

    int x;
    cout << "Enter element to search ";
    cin >> x;
    int pos = searchElement(arr, n, x);
    cout << pos;
}