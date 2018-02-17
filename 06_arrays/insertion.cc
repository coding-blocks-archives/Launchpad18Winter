// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int binarySearch(int arr[], int be, int en, int elementToFind){
    while(be <= en){
        int mid = (be + en) / 2;
        if (arr[mid] == elementToFind){
            return mid;
        }
        else if (arr[mid] < elementToFind){
            be = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    return -1;
}


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

bool pairSum(int arr[], int n, int sum){
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if (arr[i] + arr[j] == sum){
                cout << arr[i] << " " << arr[j] << endl;
                return true;
            }
        }
    }
    return false;
}

bool pairSum2(int arr[], int n, int sum){
    for(int i = 0; i < n; ++i){
        int curElem = arr[i];
        int remEle = sum - curElem;
        int pos = binarySearch(arr, i + 1, n - 1, remEle);
        if (pos != -1){
            cout << curElem << " " << remEle << endl;
            return true;
        }
    }
    return false;

}


int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);
    // insertionSort(arr, n);
    // selectionSort(arr, n);
    
    // int x; cin >> x;
    // int ans = binarySearch(arr, 0, n - 1, x);
    // cout << "element found @ " << ans;

    int x; cin >> x;
    bool ans = pairSum2(arr, n, x); 
    cout << ans << endl;

    // outputArr(arr, n);

}