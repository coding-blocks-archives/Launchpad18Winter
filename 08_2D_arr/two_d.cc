// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputMat(int mat[][4], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}

int main(){
    int mat[3][4];  
    int m, n;
    cin >> m >> n;

    inputMat(mat, m, n); 
}