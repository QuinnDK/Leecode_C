#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> BackTravel(TreeNode* node, int distance, int& ans){
    vector<int> ret;
    if (node == nullptr) return ret;
    if (node->left == nullptr && node->right == nullptr){
        ret.push_back(0);
        return ret;
    };
    auto left = BackTravel(node->left, distance, ans);
    for (auto& e : left) {
        if (++e > distance) continue;
        ret.push_back(e);
    }
    auto right = BackTravel(node->right, distance, ans);
    for (auto& e : right) {
        if (++e > distance) continue;
        ret.push_back(e);
    }

    for (auto l : left) {
        for (auto r : right) {
            ans += (l + r <= distance);
        }
    }

    return ret;
}

int countPairs(TreeNode* root, int distance) {
    int ans=0;
    BackTravel(root,distance,ans);
    return ans;
}
 
