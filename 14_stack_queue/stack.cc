// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Stack{
    class Node{
public:
    int data;
    Node* next;  
    // ctor1
    Node(int d){
        data = d;
        next = NULL;
    }
};

    Node* head;

public:
    Stack(){
        head = NULL;
    }
    bool empty(){
        return head == NULL;
    }
    int top(){
        if (empty()) return -1;
        return head->data;
    }
    void push(int x){
        Node* tmp = new Node(x);
        tmp->next = head;
        head = tmp;
    }
    void pop(){
        if(!empty()){
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    ~Stack(){
        cout << "Dtor called..\n";
        Node* tmp = NULL;
        while(head){
            tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};

int main(){

    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top()<< endl;
    cout << s.top()<< endl;

    s.pop();
    s.pop();

    cout << s.top()<< endl;

}