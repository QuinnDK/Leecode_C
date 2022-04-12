#include "TreeNode.h"

vector<int> nums;

void treversal(TreeNode* root){
    if(root==NULL) return;
    treversal(root->left);
    nums.push_back(root->val);
    treversal(root->right);
}
bool isValidBST(TreeNode* root){
    nums.clear();
    treversal(root);
    for(int i=1;i<nums.size();i++){
        if(nums[i]<=nums[i-1]) return false;
    }
    return true;
}