// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef set<string> ss;
typedef map<string, ss> mss;
typedef map<string, bool> msb;
typedef vector<string> vs;


class DirectedGraph {
    mss m;
public:
    void addEdge(string src, string dest) {
        m[src].insert(dest);
    }

    void printMap() {
        for (mss::iterator it = m.begin(); it != m.end(); ++it) {
            string curVtx = it->first;
            auto ngbrList = it->second;
            cout << curVtx << ": ";
            for (auto ngbr : ngbrList) {
                cout << ngbr << " ";
            }
            cout << endl;
        }
    }


    void tarjanTopoSort(string src, msb& visited, vs& ans) {
        visited[src] = true;
        for (ss::iterator it = m[src].begin(); it != m[src].end(); ++it) {
            if (visited[*it] == false) {
                tarjanTopoSort(*it, visited, ans);
            }
        }
        ans.push_back(src);
    }

    // toposort Indegree
    vector<string> toposort() {
        map<string, int> indegree;

        for (auto& s : m) {
            for (auto& nbr : s.second) {
                indegree[nbr]++;
            }
        }

        // indegree printing
        for (auto& ele : indegree) {
            cout << ele.first << " " << ele.second << endl;
        }

        queue<string> q;
        for(auto& ele:indegree){
            if (ele.second == 0){
                q.push(ele.first);
            }
        }

        vector<string> ans;
        
        while(q.empty() != false){
            ans.push_back(q.front());
            auto curVtx = q.front();
            q.pop();

            for(auto& n : m[curVtx]){
                indegree[n]--;
                if (indegree[n] == 0){
                    q.push(n);
                }
            }
        }
        return ans;
    }
};

int main() {
    DirectedGraph g;
    g.addEdge("passport", "ticket");
    g.addEdge("passport", "insurance");
    g.addEdge("ticket", "visa");
    // g.addEdge("insurance", "ticket");
    g.addEdge("insurance", "visa");
    g.addEdge("visa", "forex");
    g.addEdge("visa", "gifts");

    // g.printMap();
    // vector<string> ans;
    // msb visited;
    // g.tarjanTopoSort("passport", visited, ans);
    // reverse(ans.begin(), ans.end());

    auto ans = g.toposort();
    for(string& s : ans){
        cout << s << " ";
    }
}