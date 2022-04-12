#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

void traversal(TreeNode* cur,vector<int>& path,vector<string> result){
    path.push_back(cur->val);
    if(cur->left==NULL && cur->right==NULL){
        string sPath;
        for(int i=0;i<path.size()-1;i++){
            sPath+=to_string(path[i]);
            sPath+="->";
        }
        sPath+=to_string(path[path.size()-1]);
        result.push_back(sPath);
        return;
    }
    if(cur->left){
        traversal(cur->left,path,result);
        path.pop_back();
    }
    if(cur->right){
        traversal(cur->right,path,result);
        path.pop_back();
    }
}

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> result;
    vector<int> path;
    if(root==NULL) return result;
    traversal(root,path,result);
    return result;
}