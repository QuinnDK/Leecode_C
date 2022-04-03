#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > fourSum(vector<int>& nums,int target){
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    for(int k=0;k<nums.size();k++){
        if(k>0&& nums[k]==nums[k-1]){
            continue;
        }
        for(int i=k+1;i<nums.size();i++){
            if(i>k+1 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                //nums[i]+nums[k]+nums[left]+nums[right] 会出现溢出
                if(nums[i]+nums[k]>target-(nums[left]+nums[right])){
                    right--;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }else if(nums[i]+nums[k]<target-(nums[left]+nums[right])){
                    left++;
                    while(left<right && nums[left]==nums[left-1]) left++;
                }else{
                    res.push_back(vector<int>{nums[i],nums[k],nums[left],nums[right]});
                    while(left<right && nums[right]==nums[right-1]) right--;
                    while(left<right && nums[left]==nums[left+1]) left++;

                    right--;
                    left++;
                }
            }
        }
    }
    return res;
} 
int main(){
    vector<int>  nums={-1,0,1,0,-2,2};
    vector<vector<int> > res=fourSum(nums,0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}