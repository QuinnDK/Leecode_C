#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//前序遍历
vector<int> preorderTraversal(TreeNode* root){
    stack<TreeNode*> sta;
    vector<int> result;
    if(root==NULL) return result;
    sta.push(root);
    while(!sta.empty()){
        TreeNode *node=sta.top();
        sta.pop();
        result.push_back(node->val);
        if(node->right) sta.push(node->right);
        if(node->left) sta.push(node->left);
    }
    return result;
}
//中序遍历
vector<int> inorderTraversal(TreeNode* root){
    stack<TreeNode* > sta;
    vector<int> result;
    TreeNode* cur=root;
    while(cur !=NULL || !sta.empty()){
        if(cur!=NULL){
            sta.push(cur);
            cur=cur->left;
        }else{
            cur=sta.top();
            sta.pop();
            result.push_back(cur->val);

        }
    }
}

//后序遍历
vector<int> postorderTraversal(TreeNode* root){
    stack<TreeNode*> sta;
    vector<int> result;
    if(root==NULL) return result;
    sta.push(root);
    while(!sta.empty()){
        TreeNode *node=sta.top();
        sta.pop();
        result.push_back(node->val);
        if(node->left) sta.push(node->left);
        if(node->right) sta.push(node->right);
    }
    reverse(result.begin(),result.end());
    return result;
}