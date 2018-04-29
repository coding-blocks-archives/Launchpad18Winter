// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

bool simulate(vi& books, int nBooks, int nStudents, int guess) {
    int curStudent = 1;
    int curPagesAllocated = 0;

    for (auto book : books) {
        if (book + curPagesAllocated <= guess) {
            curPagesAllocated += book;
        }
        else {
            ++curStudent;
            if (curStudent > nStudents || book > guess) {
                return false;
            }
            curPagesAllocated = book;
        }
    }
    return true;
}


int minPages(vi& books, int nBooks, int nStudents) {
    sort(books.begin(), books.end());
    int totalPages = accumulate(books.begin(), books.end(), 0);

    int bestAns = totalPages;

    int low = 0;
    int high = totalPages;

    while (low <= high) {
        int mid = (low + high) / 2; // guess
        bool success = simulate(books, nBooks, nStudents, mid);
        if (success) {
            bestAns = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return bestAns;
}

int main() {
    int n;
    cin >> n;
    vi v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int nStudents;
    cin >> nStudents;

    int ans = minPages(v, n, nStudents);
    cout << ans;
}