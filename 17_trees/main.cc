#include "tree.h"
#include <iostream>
#include <queue>
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

TreeNode* levelWiseInput(){
    queue<TreeNode*> q;
    int x; cin >> x;

    if (x == -1) return NULL;

    // this means user wants to create a root
    auto root = new TreeNode(x);
    q.push(root);

    while(q.empty() == false){
        TreeNode* curPar = q.front();
        q.pop();

        cin >> x;
        if (x != -1){
            // left child is there
            curPar->left = new TreeNode(x);
            q.push(curPar->left);
        } 

        cin >> x;
        if (x != -1){
            curPar->right = new TreeNode(x);
            q.push(curPar->right);
        }
    }
    return root;
}

int main() {
    TreeNode* root = levelWiseInput();
    preOrderPrint(root);
    cout << endl;

    // int ans = cntNodes(root);
    // print(ans);

    int ans = sumNodes(root);
    print(ans);

}