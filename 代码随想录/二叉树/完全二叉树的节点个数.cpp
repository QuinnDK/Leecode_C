#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int countNodes(TreeNode* root){
    if(root==NULL) return 0;
    TreeNode* left=root->left;
    TreeNode* right=root->right;
    int leftHeight=0,rightHeight=0;

    while(left){
        left=left->left;
        leftHeight++;
    }
    while(right){
        right=right->right;
        rightHeight++;
    }
    if(leftHeight==rightHeight){
        return (2<<leftHeight)-1;
    }
    return countNodes(root->left)+countNodes(root->right);
    
}


int countNodes1(TreeNode* root) {
    queue<TreeNode*> que;
    if(root==NULL) return 0;
    que.push(root);
    int res=0;
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode* curNode=que.front();
            que.pop();
            res+=1;
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
    }
    return res;
}