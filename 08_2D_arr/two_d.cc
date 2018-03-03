// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputMat(int mat[][4], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}

void outputMat(int mat[][4], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}

void diagonalElem(int mat[][4], int m, int n) {
    int dim = min(m, n);
    for (int i = 0; i < dim; ++i) {
        cout << mat[i][i] << " ";
    }
}

void printSpiral(int mat[][4], int m, int n) {
    int elementsToPrint = m * n;
    int elementsPrintedSoFar = 0;

    // walls
    int startRow = 0;
    int endRow = m - 1;
    int startCol = 0;
    int endCol = n - 1;

    while (elementsPrintedSoFar < elementsToPrint) {
        // I have to print elements

        // print the startRow
        for (int c = startCol; c <= endCol; ++c) {
            cout << mat[startRow][c] << " ";
            ++elementsPrintedSoFar;
        }
        ++startRow;

        // print the endCol
        for (int r = startRow; elementsPrintedSoFar < elementsToPrint && r <= endRow; ++r) {
            cout << mat[r][endCol] << " ";
            ++elementsPrintedSoFar;
        }
        --endCol;

        // print the endRow
        for (int c = endCol; elementsPrintedSoFar < elementsToPrint  && c >= startCol; --c) {
            cout << mat[endRow][c] << " ";
            ++elementsPrintedSoFar;
        }
        --endRow;

        // print the startCol
        for (int r = endRow; elementsPrintedSoFar < elementsToPrint  && r >= startRow; --r) {
            cout << mat[r][startCol] << " ";
            ++elementsPrintedSoFar;
        }
        ++startCol;
    }
}

void printWave(int mat[][4], int m, int n) {
    bool upToDown = true;


    for(int c = 0; c < n; ++c){
        if (upToDown){
            for(int r = 0; r < m; ++r){
                cout << mat[r][c] << " ";
            }
        }
        else {
            for(int r = m - 1; r >= 0; --r){
                cout << mat[r][c] << " ";
            }
        }
        upToDown = !upToDown;
    }

}


int main() {
    int mat[3][4];
    int m, n;
    cin >> m >> n;

    inputMat(mat, m, n);
    outputMat(mat, m, n);

    // diagonalElem(mat, m, n);
    // printSpiral(mat, m, n);
    printWave(mat, m, n);
}