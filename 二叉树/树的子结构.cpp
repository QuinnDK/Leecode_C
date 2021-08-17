#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


// hasSubStructure函数是判断如果A,B根节点相同，B是不是A的子结构
bool hasSubStructure(TreeNode*A, TreeNode*B)
{
    if (!B)        //递归结束条件1：A的一个节点B的对应位置没有,可以认为是子结构
        return true;
    if (!A || A->val != B->val)  //递归结束条件2：B的一个节点A的对应位置没有 / A,B对应位置节点值不同，此时必然不可能是子结构
        return false;
    return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right); //返回值：继续在对应位置递归判断
}


bool isSubStructure1(TreeNode*A, TreeNode *B)
{
    if (!A || !B)   //特殊判断
        return false;
    // 根节点相同的话直接进入比较，根节点不相同看B是不是A的左/右子树的子结构
    return hasSubStructure(A, B) || isSubStructure1(A->left, B) || isSubStructure1(A->right, B);
}

