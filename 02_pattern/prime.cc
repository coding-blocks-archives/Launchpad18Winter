// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool flag = true;

    if (n <= 1) flag = false;
    
    int div = 2;
    while (div < n) {
        // check if div can divide n
        if (n % div == 0) {
            flag = false;   // assumption was wrong
            break;
        }
        div = div  + 1;
    }

    if (flag == true){
        cout << n << " is prime" << endl;
    }
    else {
        cout << n << " is not prime" << endl;
    }
}