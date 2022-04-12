#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){} 
};

TreeNode* traversal(vector<int>& preorder,vector<int>& inorder){
    if(preorder.size()==0) return NULL;
    int rootValue=preorder[0];
    TreeNode* root=new TreeNode(rootValue);

    int delimiterIndex;
    for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++){
        if(inorder[delimiterIndex]==rootValue) break;
    }

    vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiterIndex);
    vector<int> rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());

    vector<int> leftPreorder(preorder.begin()+1,preorder.begin()+1+leftInorder.size());
    vector<int> rightPreorder(preorder.begin()+1+leftInorder.size(),preorder.end());
    root->left=traversal(leftPreorder,leftInorder);
    root->right=traversal(rightPreorder,rightInorder);
    return root;
}

TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
    if(preorder.size()==0 || inorder.size()==0) return NULL;
    return traversal(preorder,inorder);
}
