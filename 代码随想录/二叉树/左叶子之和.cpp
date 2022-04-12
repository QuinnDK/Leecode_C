#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int sumOfLeftLeaves(TreeNode* root){
    if(root==NULL) return 0;
    int leftValue=sumOfLeftLeaves(root->left);
    int rightValue=sumOfLeftLeaves(root->right);
    int midValue=0;

    if(root->left && !root->left->left && !root->left->right){
        midValue=root->left->val;
    }
    int sum=midValue+leftValue+rightValue;
    return sum;
}

int sumOfLeftLeavea1(TreeNode* root){
    stack<TreeNode*> sta;
    int result=0;
    if(root==NULL) return result;
    sta.push(root);
    while(!sta.empty()){
        TreeNode* temp=sta.top();
        sta.pop();
        if(temp->left!=NULL && temp->left->left==NULL && temp->left->right==NULL){
            result+=temp->left->val;
        }
        if(temp->right) sta.push(temp->right);
        if(temp->left) sta.push(temp->left);
    }
    return result;
}