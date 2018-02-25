// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    char arr_c[100] = {'a', 'b', '\0'};
    // cout << arr_c;
    // char arr_c[] = "ab";
    // int arr_i[10] = {1, 2};

    // cin >> arr_i; // WRONG
    // cout << arr_i << endl;
    // cin >> arr_c; // right
    // arr_c[5] = "c";  // WRONG! "c" is a string, man!
    // arr_c[5] = 'c';    // RIGHT! now its a char
    // cout << arr_c << endl;
    // cin >> arr_c;
    // cout << arr_c;

    // cin >> arr_c;
    // int x; cin >> x;
    // cin.get();
    int x;
    cin >> x;
    // cout << x;
    char arr_c1[100], arr_c2[100];
    cin.getline(arr_c1, 100);
    cout << x;
    cout <<"X" << arr_c1 << "X" << endl ;
    cin.getline(arr_c2, 5);
    // int x; cin >> x;
    cout <<"X" << arr_c2 << "X" << endl ;
}