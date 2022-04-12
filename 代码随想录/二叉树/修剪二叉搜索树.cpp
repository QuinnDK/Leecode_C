#include "TreeNode.h"

TreeNode* trimBST(TreeNode* root,int low,int high){
    if(root==NULL) return NULL;
    if(root->val<  low){
        TreeNode* right=trimBST(root->right,low,high);
        return right;
    }
    if(root->val>high){
        TreeNode* left=trimBST(root->left,low,high);
        return left;
    }
    root->left=trimBST(root->left,low,high);
    root->right=trimBST(root->right,low,high);
    return root;
}