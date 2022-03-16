#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int sum=0;
    int lenth=0;
    int res=INT32_MAX;
    for(int i=0;i<nums.size();i++){
        sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum>=target){
                lenth=j-i+1;
                res=res<lenth ? res:lenth;
                cout<<res<<" ";
                break;
            }
        }
    }
    return res==INT32_MAX ? 0:res;
}

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    minSubArrayLen(target,nums);
}