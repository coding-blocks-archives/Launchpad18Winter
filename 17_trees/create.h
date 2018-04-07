#ifndef CREATE_TREE
#define CREATE_TREE

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

#endif

