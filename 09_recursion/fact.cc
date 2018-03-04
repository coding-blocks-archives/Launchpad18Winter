// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n) {
    // recursion
    if (n <= 0) {
        return 1;
    }

    int smallFactorial = fact(n - 1); // always work
    int ans = n * smallFactorial;
    return ans;
}

int fib(int n) {
    // fib returns the nth fibonacci number
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

void printInc(int n) {
    // that prints n integers in inc order and after
    // printing the number, prints a space also
    // 1_2_3_4_5_

    // Yr! what if n is 0? Can't say printInc(-1)
    if (n <= 0) return ;

    // 1_2_3_4_ recursion se
    printInc(n - 1); // same problem as original
    // 5_
    cout << n << " ";
}

void printInc1(int n) {
    if (n <= 0) return;
    printInc1(n - 1);
    cout << n << "_";
}

void printDec(int n) {
    if (n <= 0) {
        return;
    }

    cout << "_" << n;
    printDec(n - 1);
}

int power(int n, int x) {
    // n^x
    if (x <= 0) {
        return 1;
    }

    int smallPow = power(n, x - 1);
    return smallPow * n;
}

void dispArr(int arr[], int n) {
    // [1,2,3,4,5], 5
    if (n <= 0) {
        // no elements to print
        return;
    }

    dispArr(arr, n - 1);
    cout << arr[n - 1] << " ";
}

int maxElementArr(int arr[], int n) {
    if (n == 0){
        int inf = 1000000;
        return -inf;
    }
    int maxElementRemArr = maxElementArr(arr, n - 1);
    if (maxElementRemArr > arr[n - 1]) {
        return maxElementRemArr;
    }
    else {
        return arr[n - 1];
    }
}


int searchArr(int arr[], int n, int x){
    if (n <= 0){
        return -1;
    }

    int posInRemArr = searchArr(arr, n - 1, x);
    if (posInRemArr != -1){
        // element has been found
        return posInRemArr;
    }

    if (x == arr[n - 1]) return n - 1;

    return -1;
}


int searchArr(int arr[], int n, int x){
    if (n <= 0){
        return -1;
    }

    if (arr[n - 1] == x) return n - 1;

    return searchArr(arr, n - 1, x);

}

int main() {
    // int n;
    // cin >> n;

    // int ans = fact(n);
    // cout << ans;

    // int ans = fib(n);
    // cout << ans;

    // printInc1(n);
    // printDec(n);

    // int n, x;
    // cin >> n >> x;
    // int ans = power(n, x);
    // cout << ans;

    int arr[10], n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    // dispArr(arr, n);

    int ans = maxElementArr(arr, n);
    cout << ans;
}