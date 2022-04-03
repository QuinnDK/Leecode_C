#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归法
bool compare(TreeNode* left,TreeNode* right){
    if(left==NULL && right!=NULL) return false;
    else if(left!=NULL && right==NULL) return false;
    else if(left==NULL && right==NULL) return true;
    else if(left->val != right->val) return false;

    bool outside=compare(left->left,right->right);
    bool inside=compare(left->right,left->left);
    bool isSame=outside && inside;
    return isSame;
}

bool isSymmetric(TreeNode* root) {
    if(root==NULL) return  true;
    return compare(root->left,root->right);
}

//迭代法
bool isSymmetric1(TreeNode* root){
    if(root==NULL) return true;
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while(!que.empty()){
        TreeNode* leftNode=que.front();que.pop();
        TreeNode* rightNode=que.front();que.pop();
        if(!leftNode && !rightNode){
            continue;
        }
        if(!leftNode || !rightNode || leftNode->val!=rightNode->val){
            return  false;
        }
        que.push(leftNode->left);
        que.push(rightNode->right);

        que.push(leftNode->right);
        que.push(rightNode->left);
    }
    return true;
}