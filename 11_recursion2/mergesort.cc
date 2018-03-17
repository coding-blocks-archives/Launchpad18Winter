// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
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

void copy(int a[], int be, int en, int x[]){
    while(be <= en){
        x[be] = a[be];
        ++be;
    }
}

void mergeSortedArr(int a[], int be, int mid, int en) {
    int x[100];
    int y[100];
    copy(a, be, mid, x);
    copy(a, mid + 1, en, y);

    int i = be;         // x
    int j = mid + 1;    // y
    int k = be;         // arr

    while(i <= mid && j <= en){
        if (x[i] < y[j]){
            a[k] = x[i];
            ++i;
            ++k;
        }
        else {
            a[k] = y[j];
            k++;
            ++j;
        }
    }

    while(i <= mid){
        a[k] = x[i];
        ++i;
        ++k;
    }

    while(j <= en){
        a[k] = y[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int be, int en) { //[be,en]
    if (be >= en) {
        return;
    }

    int mid = (be + en) / 2;
    mergeSort(arr, be, mid);
    mergeSort(arr, mid + 1, en);
    mergeSortedArr(arr, be, mid, en);
}

/*********************************************/
// Keypad codes

void getButton(char dig, char arr[]){
    char table[][5] = {
        " ", 
        "?*$", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    int digit = dig - '0';  // index
    strcpy(arr, table[digit]);
}

void generateCodes(char inp[], int be, char ansSoFar[], int i){
    if (inp[be] == '\0'){
        ansSoFar[i] = '\0';
        cout << ansSoFar << endl;
        return;
    }

    char dig = inp[be];
    char code[10] = {};
    getButton(dig, code);

    for(int j = 0; code[j] != '\0'; ++j){
        ansSoFar[i] = code[j];
        generateCodes(inp, be + 1, ansSoFar, i + 1);
    }
}


int main() {
    /*Merge Sort*/
    // int n;
    // cin >> n;
    // int arr[100] = {};
    // inputArr(arr, n);
    // mergeSort(arr, 0, n - 1);
    // outputArr(arr, n);

    /*keypad problem*/
    char inp[100], out[100];
    cin >> inp;
    generateCodes(inp, 0, out, 0);

}