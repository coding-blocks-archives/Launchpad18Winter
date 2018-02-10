// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool checkPrime(int num) {
    int div = 2;

    while (div < num) {
        if (num % div == 0) {
            return false;
        }
        ++div;
    }

    return true;
}

void printPrime(int n) {
    for (int curNum = 2; curNum <= n; ++curNum) {
        if (checkPrime(curNum) == true) {
            cout << curNum << " ";
        }
    }
}


int main() {
    int num;
    cin >> num;

    // bool isPrime = checkPrime(num);
    // cout << isPrime;
    // if (isPrime) {
    //     cout << num << "is prime";
    // }
    // else {
    //     cout << num << " not prime";
    // }

    printPrime(num);

    return 0;
}