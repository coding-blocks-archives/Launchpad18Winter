// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n, r;
    cin >> n >> r;

    int nFact = 1;
    int rFact = 1;
    int n_rFact = 1;

    // computing nFact
    for(int x = 1; x < n; ++x){
        nFact = nFact * x;
    }   

    // computing rFact
    for(int x = 1; x < r; ++x){
        rFact = rFact * x;
    }

    // computing n_rFact
    for(int x = 1; x < n - r; ++x){
        n_rFact = n_rFact * x;
    }

    // int ncr = nFact / rFact / n_rFact;
    int ncr = nFact / (rFact * n_rFact);
    cout << ncr;
}