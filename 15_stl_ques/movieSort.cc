// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

class Movie {
public:
    string title;
    int release_date;
    void print() {
        cout << title << "\t" << release_date << endl;
    }
};

bool compareMovieRD(const Movie& a, const Movie& b) {
    // if (a.release_date < b.release_date) {
    //     return true;
    // }
    // return false;
    return a.release_date < b.release_date;
}

bool compareMovieTitle(const Movie& a, const Movie& b){
    return a.title < b.title;
}

bool compareMovieMultiLevel(const Movie& a, const Movie& b){
    if (a.release_date == b.release_date){
        return a.title > b.title;
    }
    return a.release_date < b.release_date;
}

int main() {
    Movie arr[] = {
        {"Titanic", 1972},
        {"Bahubali", 2017},
        {"3idiots", 2002},
        {"incpetion", 2011},
        {"shashank redemption", 1996},
        {"Kal ho na", 2002},
        {"DDLJ", 1994}
    };

    sort(arr, arr + 7, compareMovieMultiLevel);
    for (int i = 0; i < 7; ++i) {
        arr[i].print();
    }
}