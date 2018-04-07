#include "create.h"

#ifndef PRINT_TREE
#define PRINT_TREE

void preOrderPrint(TreeNode* root){
    if (root == NULL) return;

    preOrderPrint(root->left);
    preOrderPrint(root->right);
    cout << root->data << " ";
}

#endif