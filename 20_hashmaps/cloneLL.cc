// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "ll.h"
#include <map>
using namespace std;

void display2(Node* head) {
    Node* cur = head;
    while (cur != NULL) {               // while(cur)
        // cout << "[" << cur << "]";
        cout << cur->data;
        cout << "(" << (cur->random ? cur->random->data : 0) << ")";
        // cout << "[" << cur->random << "]";
        cout << "-->";
        cur = cur->next;
    }
}

Node* getNode(Node* head, int n) {
    int cnt = 0;
    while (head) {
        cnt++;
        if (cnt == n) return head;
        head = head->next;
    }
    return NULL;
}

Node* cloneLL(const Node* head) {
    map<const Node*, Node*> m;

    Node* head2 = NULL;
    const Node* cur1 = head;
    Node* cur2 = NULL;

    while (cur1) {
        if (head2 == NULL) {
            head2 = new Node(cur1->data);
            cur2 = head2;
            m[cur1] = head2;

        }
        else {
            cur2->next = new Node(cur1->data);
            cur2 = cur2->next;
            m[cur1] = cur2;
        }
        cur1 = cur1->next;
    }

    // setting the random pointer
    cur1 = head;
    cur2 = head2;
    while (cur1) {
        cur2->random = cur1->random ? m[cur1->random] : NULL;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return head2;
}

Node* cloneLL2(Node* head){
    Node* cur1 = head;
    Node* cur2 = NULL;

    while(cur1){
        Node* tmp = new Node(cur1->data);
        tmp->next = cur1->next;
        cur1->next = tmp;
        cur1 = cur1->next->next;
    }

    // set the random pointers
    cur1 = head;
    cur2 = cur1->next;
    while(cur1){
        cur2->random = cur1->random ? cur1->random->next : NULL;
        cur1 = cur1->next->next;
        cur2 = cur1 ? cur1->next : NULL;
    }

    // seperating the lists
    cur1 = head;
    cur2 = cur1->next;
    Node* head2 = cur2;
    while(cur1){
        Node* ahead = cur1->next->next;
        cur2->next = ahead ? ahead->next : NULL;
        cur1->next = ahead;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return head2;
}


int main() {
    Node* head = createLL();
    int nodeNo;
    Node* cur = head;
    while (cur) {
        cin >> nodeNo;
        cur->random = getNode(head, nodeNo);
        cur = cur->next;
    }

    Node* clone = cloneLL(head);
    display2(head);
    cout << endl;
    display2(clone);
}