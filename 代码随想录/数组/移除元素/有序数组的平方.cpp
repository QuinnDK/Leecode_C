#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int n=nums.size();
    int pos=n-1;
    vector<int> res(pos+1);
    for(int i=0, j=n-1; i<j;){
        if(nums[i]*nums[i]>nums[j]*nums[j]){
            res[pos]=nums[i]*nums[i];
            i++;
        }else{
            res[pos]=nums[j]*nums[j];
            j--;
        }
        pos--;
    }
    return res;
}

int main(){

}