#include<iostream>
#include<vector>
using namespace std;

// vector<int> nums;
int binary_search(int nums[],int target){
    int left=0,right=sizeof(nums)-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]<target){
            right=mid-1;
        }else if (nums[mid]==target){
            cout<< mid;
        }
    }
    return -1;
}

int left_bound(vector<int> nums,int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]==target){
            right=mid-1;
        }
    }
    if (left>=nums.size() || nums[left]!=target){
        return -1;
    }
    return left;
}

int right_bound(vector<int> nums,int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]==target){
            left=mid+1;
        }
    }
    if (right<0 || nums[right]!=target){
        return -1;
    }
    return right;
}

int main(){
    // int a[]={1,3,3,4,5,5,10,23,444};
    // vector<int>nums(a,a+sizeof(a)); 

    int nums[9] = {1,3,3,4,5,5,10,23,444};
    for (int i=0;i<9;i++){
        cout << nums[i];
    }
    binary_search(nums,3);
    // cout<<res<<endl;