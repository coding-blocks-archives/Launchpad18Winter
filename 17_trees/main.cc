#include "tree.h"
#include <iostream>
#include <queue>
#include <map>
#include <utility>
using namespace std;

int cntNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int q1 = cntNodes(root->left);
    int q2 = cntNodes(root->right);
    return q1 + q2 + 1;
}

int sumNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int q1 = sumNodes(root->left);
    int q2 = sumNodes(root->right);
    return q1 + q2 + root->data;
}

TreeNode* levelWiseInput() {
    queue<TreeNode*> q;
    int x; cin >> x;

    if (x == -1) return NULL;

    // this means user wants to create a root
    auto root = new TreeNode(x);
    q.push(root);

    while (q.empty() == false) {
        TreeNode* curPar = q.front();
        q.pop();

        cin >> x;
        if (x != -1) {
            // left child is there
            curPar->left = new TreeNode(x);
            q.push(curPar->left);
        }

        cin >> x;
        if (x != -1) {
            curPar->right = new TreeNode(x);
            q.push(curPar->right);
        }
    }
    return root;
}

void levelWiseOuptut(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* const DELIMITER = NULL;

    queue<TreeNode*> q;
    q.push(root);
    q.push(DELIMITER);

    while (q.empty() == false) {
        // nodes to process
        TreeNode* curNode = q.front();
        q.pop();

        if (curNode == DELIMITER){
            cout << endl;
            if (q.empty() == false){
                // nodes are still there to be processed
                q.push(DELIMITER);
            }
            continue;
        }
        cout << curNode->data << " ";

        if (curNode->left) q.push(curNode->left);
        if (curNode->right)q.push(curNode->right);
    }
}

void topView(TreeNode* root){
    if (root == NULL) return;

    typedef pair<int, TreeNode*> PAIR;

    queue<PAIR> q;      // pair of node* int
    map<int, TreeNode*> m;    // hd-->val

    q.push(make_pair(0, root));

    while(q.empty() == false){
        PAIR p = q.front();
        q.pop();
        TreeNode* curNode = p.second;
        int curDist = p.first;

        if (m.find(curDist) == m.end()){
            // this is the first node with horizontal dist curDist
            m[curDist] = curNode;
        }

        if (curNode->left){
            q.push(make_pair(curDist - 1, curNode->left));
        }
        if (curNode->right){
            q.push(make_pair(curDist + 1, curNode->right));
        }
    }

    typedef map<int, TreeNode*>::iterator mapIterator;   // iterator to the map

    for(mapIterator it = m.begin(); it != m.end(); ++it){
        cout << it->second->data << " ";  // second is the val
    }
    cout << endl;
}

int main() {
    TreeNode* root = levelWiseInput();
    // preOrderPrint(root);
    // cout << endl;

    // int ans = cntNodes(root);
    // print(ans);

    // int ans = sumNodes(root);
    // print(ans);

    levelWiseOuptut(root);
    topView(root);

}