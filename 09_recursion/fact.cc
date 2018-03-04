// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fact(int n){
    // recursion
    if (n <= 0){
        return 1;
    }

    int smallFactorial = fact(n - 1); // always work
    int ans = n * smallFactorial;
    return ans;
}

int fib(int n){
    // fib returns the nth fibonacci number
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
}

void printInc(int n){
    // that prints n integers in inc order and after 
    // printing the number, prints a space also
    // 1_2_3_4_5_

    // Yr! what if n is 0? Can't say printInc(-1)
    if (n <= 0) return ;

    // 1_2_3_4_ recursion se
    printInc(n -1); // same problem as original
    // 5_
    cout << n << " ";
}

void printInc1(int n){
    if (n <= 0) return;
    printInc1(n - 1);
    cout << n << "_";
}

void printDec(int n){
    if (n <= 0){
        return;
    }

    cout << "_" << n;
    printDec(n - 1);
}


int main(){
    int n;
    cin >> n;

    // int ans = fact(n);
    // cout << ans;    

    // int ans = fib(n);
    // cout << ans;

    // printInc1(n);

    printDec(n);
}