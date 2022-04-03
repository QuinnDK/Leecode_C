#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int maxdepth(TreeNode* root){
    if(root==NULL) return 0;
    return max(maxdepth(root->left),maxdepth(root->right))+1;
}

bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    if(!isBalanced(root->left)|| !isBalanced(root->right)) return false;

    int leftDepth= maxdepth(root->left);
    int rightDepth=maxdepth(root->right);

    if(abs(leftDepth-rightDepth)>1) return false;
    return true;
}