// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

class Fruit{
private:    // default access specifier
    char origin[80];
    int wt = 10, color;
public:
    Fruit(const char o[], int w, int c){
        cout << "Initialising in Progress..." << endl;
        strcpy(origin, o);  // origin = o...origin is an ARRAY
        wt = w;
        color = c;
    }

    Fruit(){
        strcpy(origin, "");
        wt  = 0;
        color = -1;
    }

    void print(){
        cout << origin << " " << "wt: " << wt << "col: " << color << endl;
    }

    void updateWeight(int newWt){
       if (newWt > 0) wt = newWt;
    }
};

int main(){
    Fruit f("India", 10, 1);    // automatically invoked
    // Fruit f;
    f.print();

    f.updateWeight(-12);         // f.wt = -12;
    f.print();

    
}