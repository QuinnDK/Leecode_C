#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int getDepth(TreeNode* root){
    if(root==NULL) return 0;
    int leftDepth=getDepth(root->left);
    int rightDepth=getDepth(root->right);

    if(root->right==NULL && root->left!=NULL){
        return leftDepth+1;
    }
    if(root->left==NULL && root->right!=NULL){
        return rightDepth+1;
    }
    int result=1+min(leftDepth,rightDepth);
    return result;
}

int minDepth(TreeNode* root){
    return getDepth(root);
}