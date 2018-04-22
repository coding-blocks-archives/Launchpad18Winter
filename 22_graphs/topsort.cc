// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef set<string> ss;
typedef map<string, ss> mss;


class DirectedGraph{
    mss m;
public:
    void addEdge(string src, string dest){
        m[src].insert(dest);
    }

    void printMap(){
        for(mss::iterator it = m.begin(); it != m.end(); ++it){
            string curVtx = it->first;
            auto ngbrList = it->second;
            cout << curVtx << ": ";
            for(auto ngbr: ngbrList){
                cout << ngbr << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    DirectedGraph g;
    g.addEdge("passport", "ticket");
    g.addEdge("passport", "insurance");
    g.addEdge("ticket", "visa");
    g.addEdge("insurance", "visa");
    g.addEdge("visa", "gifts");
    g.addEdge("visa", "forex");

    g.printMap();

    
}