#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int findBottomLeftValue(TreeNode* root){
    queue<TreeNode*> que;
    if(root!=NULL) que.push(root);
    int result=0;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode* node=que.front();
            que.pop();
            if(i==0) result=node->val;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return result;
}