#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int depath(TreeNode* root){
    if(root==nullptr) return 0;
    return max(depath(root->right),depath(root->left))+1;
}

bool isBalanced(TreeNode* root){
    if (root==nullptr) return true;

    if(abs(depath(root->left)-depath(root->right))>1){
        return false;
    }else{
        return isBalanced(root->left)&&isBalanced(root->right);
    }
}