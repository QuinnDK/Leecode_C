#include<iostream>
#include<vector>
using namespace std;

//右边界
int getRightBorder(vector<int>& nums,int target){
    int left=0;
    int right=nums.size()-1;
    int RightBorder=-2;

    while(left<=right){
        int middle=left+(right-left)/2;
        if(nums[middle]>target){
            right=middle-1;
        }else{
            left=middle+1;
            RightBorder=left;
        }
    }
    return RightBorder;
}

//左边界
int getLeftBorder(vector<int>& nums,int target){
    int left=0;
    int right=nums.size()-1;
    int LeftBorder=-2;

    while(left<=right){
        int middle=left+(right-left)/2;
        if(nums[middle]>=target){
            right=middle-1;
            LeftBorder=right;
        }else{
            left=middle+1;
        }
    }
    return LeftBorder;
}

int main(){}