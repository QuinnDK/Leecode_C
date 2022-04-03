#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//前序遍历
void traversal(TreeNode* cur, vector<int>& vec){
    if(cur==NULL) return;
    vec.push_back(cur->val);
    traversal(cur->left,vec);
    traversal(cur->right,vec);
}
//中序遍历
void traversal1(TreeNode* cur, vector<int>& vec){
    if(cur==NULL) return;
    
    traversal(cur->left,vec);
    vec.push_back(cur->val);
    traversal(cur->right,vec);
}
//后序遍历
void traversal2(TreeNode* cur, vector<int>& vec){
    if(cur==NULL) return;
    
    traversal(cur->left,vec);
    traversal(cur->right,vec);
    vec.push_back(cur->val);
}
