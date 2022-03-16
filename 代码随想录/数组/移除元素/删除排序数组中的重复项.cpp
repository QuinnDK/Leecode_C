#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int slow=1,fast=1;
    for(int fast=1;fast<n;fast++){
        if(nums[fast]!=nums[fast-1]){
            nums[slow++]=nums[fast];
        }
    }
    return slow;
}
int removeDuplicates1(vector<int>& nums){
    int n=nums.size();
    if(n==0) return 0;
    int slow=0;

    for(int fast=0;fast<n-1;fast++){
        if(nums[fast+1]!=nums[fast]){
            nums[++slow]=nums[fast+1];
        }
    }
    return slow+1;
}


int main(){

}