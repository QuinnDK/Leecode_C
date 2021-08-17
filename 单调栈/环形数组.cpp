#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i%n]){
            s.pop();
        }
        ans[i%n]=s.empty() ? -1:s.top();
        s.push(nums[i%n]);
    }
    return ans;
}