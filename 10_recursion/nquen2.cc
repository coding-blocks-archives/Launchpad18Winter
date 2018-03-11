#include <iostream>
using namespace std;

const int D = 20;
char board[D][D] = {};

void clearBoard(char mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = 'X';
        }
    }
}

void printMat(char mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

bool check(int n, int x, int y) {
    // check row or col
    for (int i = 0; i < n; ++i) {
        if (board[x][i] == 'Q') return false;
        if (board[i][y] == 'Q') return false;
    }

    // check diagonal
    for (int dist = 1; dist < n; ++dist) {
        int prRow = x - dist;
        int prCol = y - dist;
        if (prRow >= 0 && prRow <= n &&
                prCol >= 0 && prCol <= n &&
                board[prRow][prCol] == 'Q') {
            return false;
        }

        int secRow = x - dist;
        int secCol = y + dist;
        if (secRow >= 0 && secRow <= n &&
                secCol >= 0 && secCol <= n &&
                board[secRow][secCol] == 'Q') {
            return false;
        }
    }
    return true;
}

bool nqueen(int n, int r) {
    if (n == r) {
        // no row to place a queen
        // no queen to place
        return true;
    }
    for (int c = 0; c < n; ++c) {
        bool canPlace = check(n, r, c);
        if (canPlace) {
            board[r][c] = 'Q';
            // checks if recursion is successful in setting the remaining board
            bool success = nqueen(n, r + 1);
            if (success) {
                return true;
            }
            board[r][c] = 'X';
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    clearBoard(board, n, n);
    int success = nqueen(n, 0);
    if (success) {
        printMat(board, n, n);
    }
    else {
        cout << "Failed";
    }
    return 0;

}