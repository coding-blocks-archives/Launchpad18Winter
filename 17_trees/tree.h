#include <iostream>
using namespace std;

#ifndef TREE_H_
#define TREE_H_

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
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
#endif