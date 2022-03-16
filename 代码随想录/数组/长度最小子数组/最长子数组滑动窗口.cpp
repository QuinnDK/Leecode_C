#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums){
    int res=INT32_MAX;
    int sum=0;
    int i=0;
    int len=0;
    for(int j=0;j<nums.size();j++){
        sum+=nums[j];
        while(sum>=s){
            len=j-i+1;
            res=res<len? res:len;
            sum-=nums[i++];
        }
    }
    return res==INT32_MAX? 0:res;
}