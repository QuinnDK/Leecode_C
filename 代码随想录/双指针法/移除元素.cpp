#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums,int val){
    int fast=0,slow=0;

    for(;fast<nums.size();fast++){
        if(nums[fast]!=val){
            nums[slow++]=nums[fast];
        }
    }
    return slow;
}