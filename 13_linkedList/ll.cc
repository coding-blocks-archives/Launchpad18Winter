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

Node* addNumbers(Node* a, Node* b){

}

Node* midPoint(Node* head){
    Node* slow = head;   // SET
    Node* fast = head;

    // GO
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* fifthLast(Node* head){
    Node* cur = head;
    for(int i = 0; cur && i < 4; ++i){
        cur = cur->next;
    }

    // SET
    Node* srt = head;
    while(cur && cur->next){
        srt = srt->next;
        cur = cur->next;
    }
    return srt;
}

Node* bubbleSort(Node* head){

}

Node* addOne(Node* head){

}

int lenLL(Node* head){

}

Node* addNumbers(Node* a, Node* b, int lena, int lenb){ 
   if (a == NULL && b == NULL){
    return NULL;
   }

   if (!a) return b;
   if (!b) return a;

   if (lena < lenb){
    swap(a, b);
    swap(lena, lenb);
   }

   Node* ans = NULL;
   int curNum = 0, dig = 0, carry = 0;
   if (lena == lenb){
    ans = addNumbers(a->next, b->next, lena-1, lenb-1);
    if (ans){
        curNum = ans->data;
        dig = ans->data % 10;
        carry = ans->data / 10;
        ans->data = dig;
    }
    Node* curNode = new Node(carry + a->data + b->data);
    curNode->next = ans;
    return curNode; 
   }
   else{
    ans = addNumbers(a->next, b, lena-1, lenb);
    if (ans){
        curNum = ans->data;
        dig = ans->data % 10;
        carry = ans->data / 10;
        ans->data = dig;
    }
    Node* curNode = new Node(carry + a->data);
    curNode->next = ans;
    return curNode; 
   }
}

void print(Node* x){
    cout << x << " ";
    if (x){
    cout << x->data << endl;
    }
}

int main(){
    // Node* head = createLL();
    // display(head);
    // cout << "\n***********\n";
    // deleteNode(head, 2);
    
    // head = reverseLL2(head);
    // display(head);


    // Node* a = createLL();
    // Node* b = createLL();
    // Node* c = mergeLL(a, b);
    // display(c);

    // Node* head = createLL();
    // Node* mid = midPoint(head);
    // print(mid);

    // Node* head = createLL();
    // Node* ans = fifthLast(head);
    // print(ans);


    // Node* a = createLL();
    // Node* b = createLL();
    // Node* ans = addNumbers(a, b, 1, 3);
    // display(ans);
}



// reverse
// merge 2 sorted
// add numbers
// detect cycle
