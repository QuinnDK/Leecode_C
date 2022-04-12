#include"TreeNode.h"

vector<int> nums;

void traversal(TreeNode* root){
    if(root==NULL) return;
    traversal(root->left);
    nums.push_back(root->val);
    traversal(root->right);
}
int getMinimumDifference(TreeNode* root) {
    nums.clear();
    traversal(root);
    int res=INT_MAX;
    for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[i-1]< res){
            res=nums[i]-nums[i-1];
        }
    }
    return res;
}