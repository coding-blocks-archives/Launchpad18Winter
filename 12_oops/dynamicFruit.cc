// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

class Fruit {
private:    // default access specifier

    char* origin;
    int wt = 10, color;

public:
    Fruit(const char o[], int w, int c) {
        o[1] = 'a';
        int n = strlen(o);
        int sz = n + 1;
        origin = new char[sz];

        strcpy(origin, o);
        wt = w;
        color = c;
        cout << origin << " ctor called " << endl;
    }

    Fruit(const Fruit& F) {
        int sz = strlen(F.origin) + 1;
        origin = new char[sz];
        strcpy(origin, F.origin);
        wt = F.wt;
        color = F.color;
    }


    Fruit() {
        strcpy(origin, "");
        wt  = 0;
        color = -1;
    }

    void print() const {
        cout << origin << " " << "wt: " << wt << "col: " << color << endl;
    }

    void updateWeight(int newWt) {
        if (newWt > 0) wt = newWt;
    }

    void updateName(const char* o) {
        delete [] origin;
        int sz = strlen(o) + 1;
        origin = new char[sz];
        strcpy(origin, o);
    }

    ~Fruit(){
        cout << origin << " Dtor called\n";
        delete [] origin;
    }
};

void stupidFunction(){
    Fruit f1("India", 1, 2);
    // f1.clearAll();
    // f2.clearAll();
}

int main() {
    // Fruit f("India", 10, 1);    // automatically invoked
    // Fruit f;
    // f.print();
    // f.updateWeight(-12);         // f.wt = -12;
    // f.print();

    // Fruit f1("India", 10, 2);
    // Fruit f2(f1);

    // f2.updateName("United States of America");
    // f1.print();
    // f2.print();

    // stupidFunction();
    // stupidFunction();
    // stupidFunction();
    // stupidFunction();

    // playGame();

    // stupidFunction();
    // stupidFunction();

    Fruit f1("china", 1, 2);
    Fruit f2("India", 1, 2);
    Fruit f3("usa", 1, 2);
    Fruit f4("russia", 1, 2);


}