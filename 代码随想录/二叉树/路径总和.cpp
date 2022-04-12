#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//递归
bool traversal(TreeNode* cur,int count){
    if(!cur->left && !cur->right && count==0) return true;
    if(!cur->left && !cur->right) return false;

    if(cur->left){
        count-=cur->left->val;
        if(traversal(cur->left,count)) return true;
        count+=cur->left->val;
    }
    if(cur->right){
        count-=cur->right->val;
        if(traversal(cur->right,count)) return true;
        count+=cur->right->val;
    }
    return false;
}
bool hasPathSum(TreeNode* root,int sum){
    if(root==NULL) return false;
    return traversal(root,sum-root->val);
}

//迭代
bool hasPathSum1(TreeNode* root,int sum){
    if(root==NULL) return false;
    stack<pair<TreeNode*,int> > sta;
    sta.push(make_pair(root,root->val));
    while(!sta.empty()){
        pair<TreeNode*,int> node=sta.top(); sta.pop();
        if(!node.first->left && !node.first->right && sum ==node.second) return true;
        if(node.first->right){
            sta.push(make_pair(node.first->right,node.second+node.first->right->val));
        }
        if(node.first->left){
            sta.push(make_pair(node.first->left,node.second+node.first->left->val));
        }
    }
    return false;
}