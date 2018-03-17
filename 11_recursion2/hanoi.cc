// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int cnt = 0;
void hanoi(int n, char src, char dest, char helper) {
    if (n == 0) {
        return;
    }

    hanoi(n - 1, src, helper, dest);
    ++cnt;
    cout << cnt << " Disc #" << n << ": " << src << "-->" << dest << endl;
    hanoi(n - 1, helper, dest, src);
}

int main() {
    int n;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');
}