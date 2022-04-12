#include<bits/stdc++.h>
#include "TreeNode.h"

int pre;
void traversal(TreeNode* cur){
    if(cur==NULL) return;
    traversal(cur->right);
    cur->val+=pre;
    pre=cur->val;
    traversal(cur->left);
}
TreeNode* convertBST(TreeNode* root){
    pre=0;
    traversal(root);
    return root;
}