#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& nums){
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]<=nums[i]){
            s.pop();
        }
        ans[i]=s.empty() ? -1:(s.top()-i);
        s.push(i);
    }
    return ans;
}