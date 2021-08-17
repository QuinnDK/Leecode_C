#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > PrintTree(TreeNode* root){
    queue<TreeNode*> que;
    vector<vector<int> > res;
    if (root==nullptr){
        return res;
    }
    que.push(root);
    while(!que.empty()){
        vector<int> row;
        int sz=que.size();
        for (int i=0;i<sz;i++){
            TreeNode* front=que.front();
            que.pop();
            row.push_back(front->val);

            if(front->left!=nullptr){
                que.push(front->left);
            }
            if(front->right!=nullptr){
                que.push(front->right);
            }
        }
        res.push_back(row);
    }
    return res;
}