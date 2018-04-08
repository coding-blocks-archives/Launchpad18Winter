// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "tree.h"
#include <queue>
#include <map>
using namespace std;

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

bool isBST(TreeNode* root, int minVal, int maxVal){
    if (!root) return true;

    return (root->data > minVal && root->data >= maxVal) && 
            isBST(root->left, minVal, root->data) &&
            isBST(root->right, root->data, maxVal);
}



int main(){
    // TreeNode* root= createBST();
    // levelWiseOutput(root);


    TreeNode* root = levelWiseInput();
    levelWiseOutput(root);
    const int inf = 1e6;
    auto ans = isBST(root, -inf, inf);

}