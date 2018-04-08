// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include "tree.h"
#include <queue>
#include <map>
#include <stack>
using namespace std;

struct Triplet{
    int hd, level;
    TreeNode* curNode;
    Triplet(){
        hd = level = 0;
        curNode = NULL;
    }
    Triplet(int h, int l, TreeNode* cur){
        hd = h;
        level = l;
        curNode = cur;
    }
};

map<int, Triplet> m;

void bottomView(TreeNode* root, int level, int hd){
    if (root == NULL) return;

    bottomView(root->left, level + 1, hd -1);
    bottomView(root->right, level + 1, hd + 1);

    // NOW I AM ON ROOT
    if (m.find(hd) == m.end() or m[hd].level < level){
        m[hd] = Triplet(hd, level, root);
    }
}

void leftView(TreeNode* root, int curLevel, int& levelToPrint){
    if (root == NULL) return;

    if (curLevel == levelToPrint){
        cout << root->data << " ";
        ++levelToPrint;
    }

    leftView(root->left, curLevel + 1, levelToPrint);
    leftView(root->right, curLevel + 1, levelToPrint);
}

void connectLevels(TreeNode* root){
    TreeNode* start = root;

    while(start){
        TreeNode* leftMostNextLevel = NULL;
        TreeNode* child = NULL;
        TreeNode* cur = start;

        while(cur){
            if (cur->left){
                if (child){
                    child->next = cur->left;
                }
                child = cur->left;
                if (!leftMostNextLevel){
                    leftMostNextLevel = child;
                }
            }

            if (cur->right){
                if (child){
                    child->next = cur->right;
                }
                child = cur->right;
                if (!leftMostNextLevel){
                    leftMostNextLevel = child;
                }
            }
            cur = cur->next;
        }
        start = leftMostNextLevel;
    }
}


int main(){
    TreeNode* root = levelWiseInput();
    // levelWiseOutput(root);

    // bottomView(root, 0, 0);
    // // print map            // map<int, Triplet>::iterator
    // for(auto it = m.begin(); it != m.end(); ++it){
    //     cout << it->second.curNode->data << " ";
    // }     

    // int levelToPrint = 0;
    // leftView(root, 0, levelToPrint); 

    // connectLevels(root);
    // levelWiseOutput(root);
    printTree(root);
}