// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double fahrToCel(double fahr){
    double cel = (5.0 / 9.0) * (fahr - 32);
    return cel;
}

void printFahrToCel(int initial, int final, int step){
    while(initial <= final){
        double cel = fahrToCel(initial);
        cout << initial << " " << cel << endl;
        initial = initial + step;
    }
}

int main(){
    int initial, final, step;
    cin >> initial >> final >> step;

    printFahrToCel(initial, final, step);   
}