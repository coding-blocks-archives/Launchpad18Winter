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
    Node* revA = reverseLL(a);
    Node* revB = reverseLL(b);
    Node* revC = NULL;

    Node* curA = revA;
    Node* curB = revB;
    Node* tail = NULL;

    int carry = 0, dig = 0, sum = 0;

    while(curA or curB){
        sum = 0;
        if (curA) sum += curA->data;
        if (curB) sum += curB->data;
        sum += carry;
        
        dig = sum % 10;
        carry = sum / 10;

        if (revC == NULL){
            // the ones place
            revC = new Node(dig);
            tail = revC;

        }
        else {
            tail->next = new Node(dig);
            tail = tail->next;
        }
        if (curA) curA = curA->next;
        if (curB) curB = curB->next;
    }

    if (carry) {
        tail->next = new Node(carry);
        tail = tail->next;
    }

    // reset
    revA = reverseLL(revA);
    revB = reverseLL(revB);
    revC = reverseLL(revC);
    return revC;
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

Node* addOne(Node* head){
    Node* lastNonNine = head;
    Node* cur = head;
    while(cur){
        if (cur->data < 9){
            lastNonNine = cur;
        }
        cur = cur->next;
    }
    lastNonNine->data += 1;

    lastNonNine = lastNonNine->next;
    while(lastNonNine){
        lastNonNine->data = 0;
        lastNonNine = lastNonNine->next;
    }
}

int lenLL(Node* head){
    int cnt = 0;
    Node* cur = head;

    while(cur){
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

Node* copyLL(Node* head){
    Node* cur = head;
    Node* newHead = NULL;
    Node* tail = NULL;

    while(cur){
        Node* tmp = new Node(cur->data);
        if (newHead){
            newHead = tmp;
            tail = tmp;
        }
        else{
            tail->next = new Node(cur->data);
            tail = tail->next;
        }
        cur = cur->next;
    }
    return newHead;
}

Node* addNumbers(Node* a, Node* b, int lena, int lenb){ 
    if (!a){
       Node* cloneB = copyLL(b);
       return cloneB;
    }

    if (!b){
        return copyLL(a);
    }

    if (lenb > lena){
        swap(a, b);
        swap(lena, lenb);
    }

    if (lena > lenb){ 
        Node* ans = addNumbers(a->next, b, lena-1, lenb);
        int carry = 0;
        if (ans && ans->data >= 10){
            carry = ans->data / 10;
            ans->data = ans->data % 10;
        }

        Node* tmp = new Node(a->data + carry);
        tmp->next = ans;
        return tmp;
    }
    else {
        // lengths are same
        Node* ans = addNumbers(a->next, b->next, lena-1, lenb-1);
        int carry = 0;
        if (ans && ans->data >= 10){
            carry = ans->data / 10;
            ans->data = ans->data % 10;
        }

        Node* tmp = new Node(a->data + b->data + carry);
        tmp->next = ans;
        return tmp;
    }
}

void print(Node* x){
    cout << x << " ";
    if (x){
    cout << x->data << endl;
    }
}

Node* mergeSort(Node* a){
    if (a == NULL || a->next == NULL) return a;
    // if (!a or !a->next) return a;

    Node* midNode = midPoint(a);
    Node* b = midNode->next;
    midNode->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    Node* ans = mergeLL(a, b);
}

Node* bubbleSort(Node* a){
    const int len = lenLL(a);

    for(int i = 0; i < len; ++i){
        Node* curNode = a;
        Node* prevNode = NULL;

        while(curNode && curNode->next){
            Node* ahead = curNode->next;
            if (curNode->data > ahead->data){
                // swapping required
                if(curNode == a){
                    curNode->next = ahead->next;
                    ahead->next = curNode;
                    a = ahead;
                    prevNode = a;
                }
                else{
                    curNode->next = ahead->next;
                    ahead->next= curNode;
                    prevNode->next = ahead;
                    prevNode = ahead;
                }
            }
            else {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
    }
    return a;
}

bool detectCycle(Node* a){
    Node* slow = a;
    Node* fast = a;
    bool isLoop = false;

    // GO
    while(slow && fast && fast->next){  // Floyd Cycle
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            isLoop = true;
            break;
        }
    }

    slow = a;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return isLoop;
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
    // Node* ans = addNumbers(a, b);
    // display(ans);

    // Node* a = createLL();
    // addOne(a);
    // display(a);

    // Node* a = createLL();
    // Node* b = createLL();
    // Node* ans = addNumbers(a, b, lenLL(a), lenLL(b));
    // display(ans);

    // Node* a = createLL();
    // a = mergeSort(a);
    // display(a);

    // Node* a = createLL();
    // a = bubbleSort(a);
    // display(a);

    Node* a = createLL();
    a->next->next->next->next->next->next->next = 
        a->next->next->next;
    bool ans = detectCycle(a);
    display(a);
    cout << ans;


}

// reverse
// merge 2 sorted
// add numbers
// detect cycle
