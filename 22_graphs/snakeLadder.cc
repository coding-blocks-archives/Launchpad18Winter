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


class Graph {
    vvi g;
public:
    Graph(int n) {
        g.resize(n);
    }

    void addEdge(int src, int dest, bool isBiDirectional = false) {
        g[src].push_back(dest);
        if (isBiDirectional) {
            g[dest].push_back(src);
        }
    }

    int shortestPath(int src, int dest){
        const int inf = 1e6;
        vector<int> dist(g.size(), inf);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int curVtx = q.front();
            q.pop();

            for(auto& n : g[curVtx]){
                if (dist[n] == inf){
                    // not visited
                    dist[n] = 1 + dist[curVtx];
                    q.push(n);
                }
            }
        }
        return dist[dest];
    }
};

int main() {
    Graph g(36);

    vector<int> snakeLadders(36, -1);

    snakeLadders[1] = 14;
    snakeLadders[4] = 6;
    snakeLadders[8] = 26;
    snakeLadders[16] = 3;
    snakeLadders[17] = 28;
    snakeLadders[19] = 5;
    snakeLadders[24] = 34;
    snakeLadders[31] = 29;
    snakeLadders[33] = 11;

    for (int box = 0; box <= 35; ++box) {
        if (snakeLadders[box] != -1) {
            continue;
        }
        for (int dice = 1; dice <= 6; ++dice) {
            int nextBox = dice + box;
            if (nextBox <= 35) {
                if (snakeLadders[nextBox] != -1) {
                    g.addEdge(box, snakeLadders[nextBox]);
                }
                else {
                    g.addEdge(box, nextBox);
                }
            }

        }
    }

    int ans = g.shortestPath(0, 14);
    cout << ans;
}