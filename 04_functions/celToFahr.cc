// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

double fahrToCel(double fahr);  // function declaration

int main(){
    double inp;
    cin >> inp;

    double ans =  fahrToCel(inp);   // function calling
    cout << ans;
    // return 0; 
    
}

// function definition
double fahrToCel(double fahr){
    double cel = (5.0 / 9.0) * (fahr - 32);
    return cel;
}
