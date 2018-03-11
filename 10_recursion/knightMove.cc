// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;
const int D = 20;
int board[D][D] = {};

void clearBoard(int mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = 0;
        }
    }
}

void printMat(int mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int n, int x, int y){
    return (x >= 0 && x < n &&
            y >= 0 && y < n &&
            board[x][y] == 0);
}

bool knightMove(int n, int x, int y, int moveNo) {
    if (moveNo == n * n) {
        return true;
    }

    int rowDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};
    int colDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};

    for (int i = 0; i < 8; ++i) {
        int nextRow = x + rowDir[i];
        int nextCol = y + colDir[i];
        bool canPlace = check(n, nextRow, nextCol);
        if (canPlace) {
            board[nextRow][nextCol] = moveNo;
            bool success = knightMove(n, nextRow, nextCol, moveNo + 1);
            if (success) return true;
            board[nextRow][nextCol] = 0;
        }
    }
    return false;
}


int main() {
    int n;
    cin >> n;

    board[0][0] = -1;
    
    bool success = knightMove(n, 0, 0, 1);
    if (success) {
        printMat(board, n, n);
    }
    else {
        cout << "Failed";
    }
    return 0;
}