// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

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

Node* createLL(){
    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        int x;
        cin >> x;
        if (x == -1) break;

        Node* curNode = new Node(x);
        if (head == NULL){
            // curNode is the first node of our list
            head = curNode;
            tail = curNode;
        }
        else{
            tail->next = curNode;
            tail = tail->next;
        }
    }
    return head;
}

void display(Node* head){
    Node* cur = head;
    while(cur != NULL){                 // while(cur)
        cout << cur->data << "-->";
        cur = cur->next;
    }
}

void deleteNode(Node* &head, int key){
    Node* cur = head;
    Node* prevNode = NULL;

    while(cur){
        if (cur->data == key){
            if (prevNode){
                prevNode->next = cur->next;
                delete cur; // cur stores the address of the current node
            }
            else {
                // previous node is not THERE ==> cur MUST be head
                head = cur->next;
                delete cur;
            }
            break;
        }
        else {
            prevNode = cur;
            cur = cur->next;
        }
    }
}

Node* reverseLL(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* smallHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

Node* reverseLL2(Node* head){
    Node* cur = head;
    Node* prevNode = NULL;

    while(cur){
        Node* ahead = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = ahead;
    }
    return prevNode;
}

Node* mergeLL(Node* a, Node* b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data){
        a->next = mergeLL(a->next, b);
        return a;
    }
    else {
        b->next = mergeLL(a, b->next);
        return b;
    }
}


int main(){
    // Node* head = createLL();
    // display(head);
    // cout << "\n***********\n";
    // deleteNode(head, 2);
    
    // head = reverseLL2(head);
    // display(head);


    Node* a = createLL();
    Node* b = createLL();
    Node* c = mergeLL(a, b);
    display(c);


}



// reverse
// merge 2 sorted
// add numbers
// detect cycle
