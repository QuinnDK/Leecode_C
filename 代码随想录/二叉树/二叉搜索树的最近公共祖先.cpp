#include "TreeNode.h"

TreeNode* traversal(TreeNode* cur,TreeNode* p,TreeNode* q){
    if(cur==NULL) return cur;
    if(cur->val > p->val && cur->val > q->val){
        TreeNode* left=traversal(cur->left,p,q);
        if(left!=NULL) return left;
    }
    if(cur->val < p->val && cur->val < q->val){
        TreeNode* right=traversal(cur->right,p,q);
        if(right!=NULL) return right;
    }
    return cur;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traversal(root, p, q);
}
