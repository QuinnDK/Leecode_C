#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){} 
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    TreeNode* node=new TreeNode(0);
    if(nums.size()==0){
        node->val=nums[0];
        return node;
    }
    int maxValue=0;
    int maxValueIndex=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>maxValue){
            maxValue=nums[i];
            maxValueIndex=i;
        }
    }
    node->val=maxValue;
    if(maxValueIndex>0){
        vector<int> newVec(nums.begin(),nums.begin()+maxValueIndex);
        node->left=constructMaximumBinaryTree(newVec);
    }
    if(maxValueIndex<nums.size()-1){
        vector<int> newVec(nums.begin()+maxValueIndex+1,nums.end());
        node->right=constructMaximumBinaryTree(newVec);
    }
    return node;
}