#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > res;

void backtrack(vector<int>& nums,int start,vector<int>& strack);

vector<vector<int> > subsets(vector<int>& nums){
    vector<int > track;
    backtrack(nums,0,track);
    return res;
}

void backtrack(vector<int>& nums,int start,vector<int>& strack){
    res.push_back(strack);
    for (int i=start;i<nums.size();i++){
        strack.push_back(nums[i]);
        backtrack(nums,i+1,strack);
        strack.pop_back();
    }
}