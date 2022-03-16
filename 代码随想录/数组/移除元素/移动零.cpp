#include<iostream>
#include<vector>
using namespace std;


void moveZeroes(vector<int>& nums){
    int fast=0,slow=0;
    for (fast=0;fast<nums.size();fast++){
        if(nums[fast]!=0){
            nums[slow++]=nums[fast];
        }
    }
    while(slow<nums.size()){
        nums[slow++]=0;
    }
}


int main(){

}