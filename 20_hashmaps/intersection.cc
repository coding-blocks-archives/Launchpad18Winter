// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "ll.h"
#include <set>
using namespace std;

Node* findIntersectionNode(Node* head1, Node* head2){
    // mappify the first ll
    Node* cur = head1;
    set<Node*> s;

    while(cur){
        s.insert(cur);
        cur = cur->next;
    }

    // check in another list for the curNode
    Node* cur2 = head2;
    while(cur2){
        if (s.find(cur2) != s.end()) return cur2;
        cur2 = cur2->next;
    }

    return NULL;
}


int main(){
    Node* head1 = createLL();

    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = head1->next->next->next;
    display(head1);
    cout << endl;
    display(head2);

    Node* ans = findIntersectionNode(head1, head2);
    cout << ans->data;
}