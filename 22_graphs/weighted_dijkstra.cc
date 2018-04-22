// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define mp make_pair
#define id first
#define dist second
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

class WeightedGraph {
    vvii g;

    class Compare {
    public:
        bool operator()(ii& a, ii& b) {
            // shall a come before b
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };

public:
    WeightedGraph(int n) {
        g.resize(n + 1);
    }

    void addEdge(int src, int dest, int wt) {
        g[src].push_back(make_pair(dest, wt));
        g[dest].push_back(make_pair(src, wt));
    }

    int dijkstra(int src, int dest) {
        priority_queue<ii, vii, Compare> q;
        const int inf = 1e6;
        vi distSrc(g.size(), inf);

        distSrc[src] = 0;
        q.push(make_pair(src, 0));

        while (q.empty() == false) {
            ii curVtx = q.top();
            q.pop();

            if (curVtx.dist > distSrc[curVtx.id]) continue;

            distSrc[curVtx.id] = curVtx.dist;

            for (int i = 0; i < g[curVtx.id].size(); ++i) {
                int distOfNgbrFrmSrc = g[curVtx.id][i].dist + distSrc[curVtx.id];
                int nbrId = g[curVtx.id][i].id;
                if (distOfNgbrFrmSrc < distSrc[nbrId]) {
                    // nbrId is not visited
                    q.push(make_pair(nbrId, distOfNgbrFrmSrc));
                }
            }
        }
        for(auto i : distSrc) cout << i << " ";
        return distSrc[dest];
    }
};

int main() {
    WeightedGraph g(7);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 80);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 5, 20);
    g.addEdge(3, 4, 70);
    g.addEdge(5, 6, 50);
    g.addEdge(5, 7, 10);
    g.addEdge(6, 7, 5);

    int ans = g.dijkstra(5, 4);
    cout << ans;



}