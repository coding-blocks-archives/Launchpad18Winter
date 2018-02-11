// Deepak Aggarwal, deepak@codingblocks.com
// https://github.com/aggarwaldeepak/
#include <iostream>
#include <cmath>
using namespace std;

int decToBin(int n){
    int bin = 0;
    // int mul = 1;
    while(n != 0){
        // do some processing
        int rem = n % 2;
        // cout << rem;
        bin = bin + (rem * mul);
        // mul  = mul * 10;

        n = n / 2;
    }
    return bin;
}


int main(){
    int n;
    cin >> n;

    int ans = decToBin(n);
    cout << ans;

    return 0;
}