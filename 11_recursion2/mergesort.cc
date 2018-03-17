// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int be, int en){  //[be,en]
    if (be >= en){
        return;
    }

    int mid = (be + en) / 2;
    mergeSort(arr, be, mid);
    mergeSort(arr, mid + 1, en);
    mergeSortedArr(arr, be, mid, en);
}




int main() {
    int n;
    cin >> n;
    int arr[100] = {};
    inputArr(arr, n);
    mergeSort(arr, 0, n-1);
    outputArr(arr, n);
}