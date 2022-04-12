#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
    if (postorder.size() == 0) return NULL;
    int rootValue=postorder[postorder.size()-1];
    TreeNode* root=new TreeNode(rootValue);
    if(postorder.size()==1) return root;

    int delimiterIndex;
    for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++){
        if(inorder[delimiterIndex]==rootValue) break;
    }

    vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiterIndex);
    vector<int> rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());
    
    postorder.resize(postorder.size()-1);
    vector<int> Leftpostorder(postorder.begin(),postorder.begin()+leftInorder.size());
    vector<int> Rightpostorder(postorder.begin()+leftInorder.size(),postorder.end());

    root->left=traversal(leftInorder,Leftpostorder);
    root->right=traversal(rightInorder,Rightpostorder);
    return root;
}

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
    if(inorder.size()==0 || postorder.size()==0) return NULL;
    return traversal(inorder,postorder);
}