#include <iostream>
#include <queue>
using namespace std;

#ifndef TREE_H_
#define TREE_H_

class TreeNode {
public:
    int data;
    TreeNode *left, *right, *next;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

TreeNode* insertIntoBst(TreeNode* root, int x){
    if (!root) return new TreeNode(x);

    if (x < root->data){
        root->left = insertIntoBst(root->left, x);
    }
    else {
        root->right = insertIntoBst(root->right, x);
    }
    return root;
}

TreeNode* createBST(){
    int x;
    TreeNode* root = NULL;
    while(cin >> x && x != -1){
        root = insertIntoBst(root, x);
    }
    return root;
}

void levelWiseOutput(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* const DELIMITER = NULL;

    queue<TreeNode*> q;
    q.push(root);
    q.push(DELIMITER);

    while (q.empty() == false) {
        // nodes to process
        TreeNode* curNode = q.front();
        q.pop();

        if (curNode == DELIMITER) {
            cout << endl;
            if (q.empty() == false) {
                // nodes are still there to be processed
                q.push(DELIMITER);
            }
            continue;
        }
        cout << curNode->data;
        // cout << "(" << (curNode->next ? curNode->next->data : 0) << ")" << "-->";
        cout << " ";

        if (curNode->left) q.push(curNode->left);
        if (curNode->right)q.push(curNode->right);
    }
}

#endif