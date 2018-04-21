// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef queue<int> qi;


class Graph{
    vvi g;
public:
    Graph(int n){
        g.resize(n);
    }

    void addEdge(int src, int dest, bool isBiDirectional = true){
        g[src].push_back(dest);
        if (isBiDirectional){
            g[dest].push_back(src);
        }
    }

    void printGraph(){
        for(int i = 0; i < g.size(); ++i){
            cout << i << ": ";
            for(int ngbr : g[i]){
                cout << ngbr << " ";
            }
            cout << endl;
        }   
    }

    void dfs(int src, vb& visited){
        cout << src << " ";
        visited[src] = true;

        for(int i = 0; i < g[src].size(); ++i){
            int curNgbr = g[src][i];
            if (visited[curNgbr] == false){
                dfs(curNgbr, visited);
            }
        }
    }

    void dfs(int src){
        vb visited(g.size(), false);
        dfs(src, visited);
    }


    void bfs(int src){
        qi q;
        vb visited(g.size());

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int curVtx = q.front(); q.pop();
            cout << curVtx << " ";

            for(int i = 0; i < g[curVtx].size(); ++i){
                int curNgbr = g[curVtx][i];
                if (!visited[curNgbr]){
                    q.push(curNgbr);
                    visited[curNgbr] = true;
                }
            }
        }
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    // g.printGraph();

    // g.dfs(1);
    g.bfs(4);

}