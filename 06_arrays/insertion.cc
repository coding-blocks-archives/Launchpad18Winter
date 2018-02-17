// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int tmp = arr[i];
        int j = i - 1;
        while(j >= 0 && tmp < arr[j]){
            arr[j + 1] = arr[j];
            --j;
        }
        // arr[j] < tmp
        arr[j + 1] = tmp;
    }
}

int largest(int arr[], int be, int en){
    int pos = be;
    while(be <= en){
        if (arr[be] > arr[pos]){
            pos = be;
        }
        ++be;
    }
    return pos;
}

void selectionSort(int arr[], int n){
    for(int endIndex = n - 1; endIndex >= 1; --endIndex){
        int pos = largest(arr, 0, endIndex);
        swap(arr[endIndex], arr[pos]);
    }
}

void inputArr(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void outputArr(int arr[], int n){
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }
}


int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);
    // insertionSort(arr, n);
    selectionSort(arr, n);
    outputArr(arr, n);

}