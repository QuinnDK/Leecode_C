#include<iostream>
#include<vector>
using namespace std;

//左闭右闭
int search(vector<int>& nums,int target){
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int middle=left+(right-left)/2;
        if(nums[middle]>target){
            right=middle-1;
        }else if(nums[middle]<target){
            left=middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}

//左闭右开
int search1(vector<int>& nums,int target){
    int left=0;
    int right=nums.size()-1;
    while(left<right){
        int middle=left+(right-left)/2;
        if(nums[middle]>target){
            right=middle;
        }else if(nums[middle]<target){
            left=middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}


int main(){

}