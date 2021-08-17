#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums){
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i]){
            s.pop();
        }
        ans[i]=s.empty() ? -1:s.top();
        s.push(nums[i]);
    }
    return ans;
}