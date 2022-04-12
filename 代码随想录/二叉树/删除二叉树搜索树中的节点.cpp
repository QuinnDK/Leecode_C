#include "TreeNode.h"

TreeNode* deleteNode(TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->val==key){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }else if(root->left==NULL){
            TreeNode* retNode=root->right;
            delete root;
            return retNode;
        }else if(root->right==NULL){
            TreeNode* reNode=root->left;
            delete root;
            return reNode;
        }else{
            TreeNode* rightNode=root->right;
            while(rightNode->left!=NULL){
                rightNode=rightNode->left;
            }
            rightNode->left=root->left;
            TreeNode* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
    }
    if(root->val < key) root->right=deleteNode(root->right,key);
    if(root->val > key) root->left=deleteNode(root->left,key);
    return root;
}