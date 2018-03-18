// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
#define PPP(x) cout << #x << endl;

class Pen {
private:
    char brand[10];
    int color;
    int thickness;
    int price;
    int type;
public:
    // void setDataMembers(const char br[], int c, int t, int p, int ty){
       Pen(const char br[], int c, int t, int p, int ty){
        cout << "Ctor 1 called " << endl;
        strcpy(brand, br);
        color = c;
        thickness = t;
        price = p;
        type = ty;
    }

    Pen(const char br[], int c, int t){
        cout << "Ctor 2 called. Initalising brand, col, thickness..." << endl;
        strcpy(brand, br);
        color = c;
        thickness = t;
    }
    void write(const char str[]){
        cout << str << " is being written by " << brand << " using color " << color << endl; 
    }

    void setColor(int c){
        color = c;
    }

    void printPen(){
        cout << "Brand\t:" << brand << endl;
        cout << "thickness:" << thickness << endl;
        cout << "color\t:" << color << endl;
        cout << "/**********PEN END************/" << endl; 
    }
};


int main() {
    Pen p1("Rotomac", 2, 3, 10, 0);
    Pen p2("Luxor", 2, 3);

    // Pen p;
    // p.color = 2;        // 2 RED
    // p.setColor(2);
    // p1.write("CB");
    // p2.write("CB");

    Pen p3 = p1;    // initialisation
    p3=p2;          // assignment
    PPP(p1);
    p1.printPen();
    PPP(p3);
    p3.printPen();
}