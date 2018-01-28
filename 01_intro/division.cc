// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int quotient, divisor, dividend;
    cin >> dividend >> divisor;

    if (divisor != 0) {
        quotient = dividend / divisor;
        cout << quotient;
    }
    else {
        cout << "Sorry man! Maths don;t allow divison with zero!";
    }
}