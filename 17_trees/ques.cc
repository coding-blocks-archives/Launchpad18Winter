// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createTree(){
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

void preOrderPrint(TreeNode* root){
    if (root == NULL) return;

    preOrderPrint(root->left);
    preOrderPrint(root->right);
    cout << root->data << " ";
}

int height(TreeNode* root){
    if (!root) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}

void print(int ans){
    cout << ans << endl;
}

int main(){
    TreeNode* root = createTree();
    preOrderPrint(root);
    cout << endl;

    int ans = height(root);
    print(ans);
    
}