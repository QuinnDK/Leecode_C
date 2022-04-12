#include "TreeNode.h"

void searchBST(TreeNode* cur,unordered_map<int,int>& map){
    if(cur==NULL) return;
    map[cur->val]++;
    searchBST(cur->left,map);
    searchBST(cur->right,map);
    return;
}

vector<int> findMode(TreeNode* root){
    unordered_map<int,int> map;
    vector<int> res;

    if(root==NULL) return res;
    searchBST(root,map);
    vector<pair<int,int> > vec(map.begin(),map.end());
    sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int>& b){
        return a.second > b.second;
    });

    res.push_back(vec[0].first);
    for(int i=1;i<vec.size();i++){
        if(vec[0].second==vec[i].second){
            res.push_back(vec[i].first);
        }
    }
    return res;
}