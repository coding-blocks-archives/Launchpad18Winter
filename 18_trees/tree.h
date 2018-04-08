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

TreeNode* createTree() {
    int x;
    cin >> x;

    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    // cout << "Left child of " << root->data << " ";
    root->left = createTree();
    // cout << "Right child of " << root->data << " ";
    root->right = createTree();
    return root;
}

void print(int ans) {
    cout << ans << endl;
}

void preOrderPrint(TreeNode* root) {
    if (root == NULL) return;

    preOrderPrint(root->left);
    preOrderPrint(root->right);
    cout << root->data << " ";
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
        cout << "(" << (curNode->next ? curNode->next->data : 0) << ")" << "-->";
        cout << " ";

        if (curNode->left) q.push(curNode->left);
        if (curNode->right)q.push(curNode->right);
    }
}
#endif