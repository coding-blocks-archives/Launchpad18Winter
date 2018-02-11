// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int& x, int& y){
    // cout << y << " " << x;
    int tmp = x;
    x = y;
    y = tmp;
}


void bubbleSort(int arr[], int n){
    for(int curSize = n; curSize > 0; --curSize){
        for(int i = 0; i < curSize; ++i){
            // if (i + 1 < curSize && arr[i] > arr[i + 1]){
            if (arr[i] > arr[i + 1] && i + 1 < curSize){
                mySwap(arr[i], arr[i + 1]);
            }
        }
    }
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }   

    bubbleSort(arr, n - 1);
    printArr(arr, n);
}