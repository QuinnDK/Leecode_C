#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums,int mid,int m){
    int max1=0;
    int min1=100000;
    int k=1;
    for(int i=1;i<=nums.size()-1;i++){
        max1=max1>nums[i] ? max1:nums[i];
        min1=min1<nums[i] ? min1:nums[i];
        if(max1-min1>mid){
            k++;
            max1=nums[i];
            min1=nums[i];
        }
    }
    if(k<=m){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n+1);
    for(int i = 1;i <= n; i++) {
        cin >> nums[i];
    }
    int l=0, h=100000;
    int mid=(h+l)/2;
    while(l<h){
        if(check(nums,mid,k)){
            h=mid;
        }else{
            l=mid+1;
        }
        mid=(h+l)/2;
    }
    cout<<mid;
}