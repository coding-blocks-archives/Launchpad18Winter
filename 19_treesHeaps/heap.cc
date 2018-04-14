// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Heap {
    vector<int> v;
    int sze;
    int left(int i) { return 2 * i;}
    int right(int i){ return 2 * i + 1;}
    int parent(int i){ return i / 2;}
    void heapify(int i){
        int pos = i;

        if (left(i) <= sze && v[i] < v[left(i)]){
            pos = left(i);
        }
        if (right(i) <= sze && v[pos] < v[right(i)]){
            pos = right(i);
        }

        if (pos != i){
            swap(v[pos], v[i]);
            heapify(pos);
        }
    }
public:
    Heap(){
        v.push_back(-1);
        sze = 0;
    }

    void push(int x){
        v.push_back(x);
        ++sze;
        int i = sze;
        while(parent(i) >= 1 && v[i] > v[parent(i)]){
            swap(v[i], v[parent(i)]);
            i = parent(i);
        }
    }

    void pop(){
        if (sze == 0) return;

        swap(v[1], v[sze]);
        v.pop_back();
        --sze;
        heapify(1);
    }

    int top(){
        if (sze == 0) return -1;
        return v[1];
    }
};

class Compare{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};

void printBestK(int arr[], int n, int k){
    priority_queue<int, vector<int>, Compare> pq;
    
    for(int i = 0; i < k; ++i){
        pq.push(arr[i]);
    }

    for(int i = k; i < n; ++i){
        pq.push(arr[i]);
        pq.pop();
    }

    while(pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }
   
}


int main() {
    // Heap h;
    // h.push(5);
    // h.push(7);
    // h.push(9);
    // h.push(4);
    // h.push(-3);
    // h.push(-7);
    // h.push(6);

    // cout << h.top() << endl; h.pop();
    // cout << h.top() << endl; h.pop();
    // cout << h.top() << endl; h.pop();
    // cout << h.top() << endl; h.pop();
    // cout << h.top() << endl; h.pop();

    int arr[] = {5, 2, 3, 1, 4, 6};
    printBestK(arr, 6, 3);

}