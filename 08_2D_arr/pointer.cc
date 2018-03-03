// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int foo(int arr[]);

int main(){
    // int x =65;

    // // int* p1 = &x;
    // char* p1 = (char*) &x;
    
    // int* p1, p2; // DANGER!!!

    // cout << x << endl;  
    // cout << p1 << endl; // address of x
    // cout << *(p1+1) << endl;   // value @ x


    // Operation with pointer
    // p1 + p2
    // p1 - p2  // VALID. When same type
    // p3 * p4
    // p4 / p3


    // ptr arithmetic
    // char arr_c[10];
    // int arr_i[10];

    // cout << (&arr_i[4]) - (&arr_i[0]);

    // char c1, c2;
    // cout << (&c1) - (&c2);

    // int* p1 = NULL;
    // cout << p1 << endl;
    // cout << *p1;
    // // *p1 = 100;

    // ARRAYS and POINTERS
    int arr[10] = {10, 20, 30, 40, 50};
    // // cout << arr << endl;
    // // cout << &arr[0] << endl;

    // int *p1 =  &arr[0] + 1;
    // int *p2 = arr;
    // cout << p1 << endl;
    // cout << p2 << endl;
    // cout << p1[2] << endl; // automatically dereference
    // cout << p1 + 2 << endl;

    // // p1 = NULL;
    // // arr = NULL;

    // cout << sizeof(p1) << endl;
    // cout << sizeof(arr) << endl;
    // foo(arr);

    int (*p1)[10] = &arr;   // POINTER TO AN ARRAY
    int mat[2][4];      // 
    auto p2 = &arr + 1;
    cout << p2 << endl;
    cout << p1 << endl;
    cout << p2 - p1;

}

int foo(int arr[]){
    cout << sizeof(arr);
}