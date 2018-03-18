// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw "Division By Zero";
    return a / b;
}

int main() {
    try {
        // int x = 1;
        // int y  = 0;
        // if (y == 0) throw "Division by Zero";
        int ans = divide(1, 0);
        // throw;
        // cout << ans;
    }
    catch (const char* s ) {
        cout << s << endl;
    }

}