#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value):
        value(value),left(nullptr),right(nullptr){}
};


bool isInBST(Node* root,int target){
    if (root == NULL) return false;
    if (root->value==target) return true;
    if (root->value<target) isInBST(root->right,target);
    if (root->value>target) isInBST(root->left,target);
}