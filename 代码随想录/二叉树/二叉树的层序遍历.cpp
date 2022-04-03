#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > levelOrder(TreeNode* root){
    vector<vector<int> > result;
    queue<TreeNode*> que;
    if(root!=NULL) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i=0;i<size;i++){
            TreeNode* cur=que.front();
            que.pop();
            vec.push_back(cur->val);
            if(cur->left){
                que.push(cur->left);
            }
            if(cur->right){
                que.push(cur->right);
            }   
        }
        result.push_back(vec);
    }
    return result;
}