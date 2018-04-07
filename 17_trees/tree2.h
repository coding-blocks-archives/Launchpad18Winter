#include "tree.h"
void preOrderPrint(TreeNode* root){
    if (root == NULL) return;

    preOrderPrint(root->left);
    preOrderPrint(root->right);
    cout << root->data << " ";
}
