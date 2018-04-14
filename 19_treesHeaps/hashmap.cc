// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    string name, number;
    Node* next;

    Node(string& s1, string& s2) {
        name = s1;
        number = s2;
        next = NULL;
    }
};

class HashMap {
    Node** table;
    int capacity;
    int sze;

    void setMapToNull(Node* arr[], int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = NULL;
        }
    }

    void insertIntoMap(Node* p) {
        int code = hashCode(p->name);
        Node* &head = table[code];
        if (head == NULL) {
            head = p;
        }
        else {
            p->next = head;
            head = p;
        }
    }

    int hashCode(string& s) {
        int ans = 0;
        int mod = capacity;
        int mul = 1;

        for (int i = 0; i < s.size(); ++i) {
            char curChar = s[i] % capacity;
            ans += (curChar * mul);
            mul = (mul * 31) % mod;
            ans %= mod;
        }
        return ans;
    }

    double load_factor() {
        return (double)sze / capacity;
    }

    void rehash() {
        Node** oldTable = table;
        int oldCapacity = capacity;
        capacity = 2 * oldCapacity;
        table = new Node*[capacity];
        setMapToNull(table, capacity);

        for (int i = 0; i < oldCapacity; ++i) {
            Node* head = oldTable[i];
            while (head) {
                Node* ahead = head->next;
                head->next = NULL;
                insertIntoMap(head);
                head = ahead;
            }
        }
        delete [] oldTable;
    }

public:
    HashMap() {
        capacity = 7;
        sze = 0;
        table = new Node*[capacity];
        setMapToNull(table, capacity);
    }

    void insert(string name, string num) {
        if (load_factor() > 0.7) rehash();
        Node* p = new Node(name, num);
        insertIntoMap(p);
        ++sze;
    }

    string getNumber(string& name) {

    }

    void deleteContact(string& name) {

    }

    ~HashMap() {

    }

    void printMap() {
        for (int i = 0; i < capacity; ++i) {
            Node* head = table[i];
            cout << i << "-->";
            while (head) {
                cout << head->name << "(" << head->number << ")" << " ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap h;
    h.insert("abc", "123");
    cout << endl;
    h.printMap();
    cout << endl;
    
    h.insert("def", "123");
    cout << endl;
    h.printMap();
    cout << endl;
    
    h.insert("ghi", "123");
    cout << endl;
    h.printMap();
    cout << endl;
    
    h.insert("jkl", "123");
    cout << endl;
    h.printMap();
    cout << endl;
    
    h.insert("mno", "123");
    cout << endl;
    h.printMap();
    cout << endl;

    h.insert("pqr", "123");
    cout << endl;
    h.printMap();
  
    h.insert("stu", "123");
    cout << endl;
    h.printMap();

    h.insert("vwx", "123");
    cout << endl;
    h.printMap();

    h.insert("kareena", "123");
    cout << endl;
    h.printMap();

}