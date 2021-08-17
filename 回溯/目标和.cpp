#include<iostream>
#include<vector>
using namespace std;


int result=0;
void backtrack(vector<int>nums , int i ,int target);
int fingTargetSumWays(vector<int> nums, int target){
    if (nums.size()==0)return 0;
    backtrack(nums,0,target);
    return result;
}

void backtrack(vector<int>nums , int i ,int target){
    if (i==nums.size()){
        if (target==0){
            result++;
        }
        return;
    }

    //选择减号
    target+=nums[i];
    backtrack(nums,i+1,target);
    target-=nums[i];

    //选择加号；
    target-=nums[i];
    backtrack(nums,i+1,target);
    target+=nums[i];

}