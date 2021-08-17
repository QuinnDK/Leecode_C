#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* getMin(TreeNode* node);
TreeNode* deleteNode(TreeNode* root,int key){
    if (!root) return new TreeNode();
    if(root->val==key){
        //删除
        if (root->left==NULL)return root->right;
        if (root->right==NULL) return root->left;

        TreeNode* minNode=getMin(root->right);
        root->val=minNode->val;
        root->right=deleteNode(root->right,minNode->val);

    }else if(root->val<key){
        root->right=deleteNode(root->right,key);
    }else if(root->val>key){
        root->left=deleteNode(root->left,key);
    }
}

TreeNode* getMin(TreeNode* node){
    while (node->left!=NULL) node=node->left;
    return node;
}