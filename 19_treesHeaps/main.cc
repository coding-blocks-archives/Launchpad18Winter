// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "bst.h"
#include <utility>
using namespace std;
#define head first
#define tail second

typedef pair<TreeNode*, TreeNode*> pht;

pht bstToLL(TreeNode* root){
    if (root == NULL){
        return pht(NULL, NULL);   // 0 == NULL   
    }

    pht leftAns = bstToLL(root->left);
    pht rightAns = bstToLL(root->right);

    pht ans(NULL, NULL);

    if (leftAns.tail != NULL){
        leftAns.tail->right = root;
        ans.head = leftAns.head;
    }
    else {
        ans.head = root;
    }

    if (rightAns.head != NULL){
        root->right = rightAns.head;
        ans.tail = rightAns.tail;
    }
    else {
        ans.tail = root;
    }
    return ans;
}


int main(){
    TreeNode* root = createBST();
    pht ans = bstToLL(root);
    TreeNode* curHead = ans.head;
    while(curHead){
        cout << curHead->data << " ";
        curHead = curHead->right;
    }
}