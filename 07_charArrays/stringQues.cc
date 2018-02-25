// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int stringLen(char str[]){
    int cnt = 0;
    for(int i = 0; str[i] != '\0'; ++i){
        ++cnt;
    }
    return cnt;
}

bool isPalindrome(char str[]){
    int start = 0;
    int end = stringLen(str) - 1;
    while(start < end){
        if (str[start] != str[end]) return false;
        ++start;
        --end;
    }
    return true;
}

void rotate(char str[]){
    char startChar = str[0];
    
    int i = 0;
    while(str[i] != '\0'){
        str[i] = str[i+1]; 
        ++i;
    }
    if (i == 0) return; // string was empty
    str[i - 1] = startChar;
}

void rotatek(char str[], int k){
    int len = stringLen(str);
    if (len == 0) return;

    k = k % len;

    char tmp[100];
    // copy first k chars
    for(int i = 0; i < k; ++i){
        tmp[i] = str[i];
    }

    // shift remchars
    for(int i = k, j = 0; i < len; ++i){
        str[j] = str[i];
        ++j;
    }

    // copy from tmp to str
    for(int i = k-1, j = len - 1; i >= 0; --i){
        str[j] = tmp[i];
        --j;
    } 
}

int findSortRotated(int arr[], int n, int x){
    int be = 0;
    int en = n - 1;

    while(be <= en){
        int mid = (be + en) / 2;
        if (arr[mid] == x) return mid;

        // if left is sorted
        if (arr[mid] >= arr[be]){
            // if element in the left
            if (x >= arr[be] && x <= arr[mid]){
                en = mid - 1;
            }
            else {
            // else search in the right
                be = mid + 1;
            }
        }
        else {
            // right one is sorted
            // if in the right
            if (arr[mid] <= x && arr[en] >= x){
                be = mid + 1;
            }
            else {
            // else search in the left
                en = mid - 1;
            }
        }
    }
    return -1 ;
}

void removeConsDup(char str[]){
    int pos = 0;
    int len = stringLen(str);
    if (len == 0) return;
    
    for(int i = 0; i < len; ++i){
        if (str[pos] != str[i]){
            ++pos;
            str[pos] = str[i];
        }
    }
    
    str[pos + 1] = '\0';

    // for(int i = 0; i < len; ++i){
    //     cout << str[i];
    // }
}

int main(){
    char str[100];
    cin.getline(str, 99);
    
    // int len = stringLen(str);
    // cout << len;

    // bool ans = isPalindrome(str);
    // cout << ans;

    // rotate(str);
    // cout << str;

    // int k; cin >> k;
    // rotatek(str, k);
    // cout << str;

    // int arr[10];
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; ++i) cin >> arr[i];

    // int x; cin >> x;
    // int ans = findSortRotated(arr, n, x);
    // cout << ans;

    removeConsDup(str);
    // cout << str;
}