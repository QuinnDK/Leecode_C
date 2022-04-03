#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//前序求的就是深度，使用后序求的是高度。

//层序遍历求深度
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;
    queue<TreeNode*> que;
    que.push(root);
    int depth=0;
    while(!que.empty()){
        int size=que.size();
        depth++;
        for(int i=0;i<size;i++){
            TreeNode* curNode=que.front();
            que.pop();
            if(curNode->left) que.push(curNode->left);
            if(curNode->right) que.push(curNode->right);
        }
    }
    return depth;
}
//递归
class Solution{
public:
    int getdepth(TreeNode* node){
        if(node==NULL) return 0;
        int leftDepth=getdepth(node->left);
        int rightDepth=getdepth(node->right);
        int depth=1+max(leftDepth,rightDepth);
        return depth;
    }
    int maxdepth(TreeNode* root){
        if(root==NULL) return 0;
        return getdepth(root);
    }
};