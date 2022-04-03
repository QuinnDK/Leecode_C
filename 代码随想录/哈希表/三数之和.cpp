#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(map.find(target-nums[i])!=map.end()){
            return {map[target-nums[i]],i};
        }
        map.insert(make_pair(nums[i],i));
    }
    return {};
}

vector<vector<int> > threeSum(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            return res;
        }
        if(i>0&& nums[i]==nums[i-1]){
            continue;
        }
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){
            if(nums[i]+nums[left]+nums[right]>0){
                right--;
                while(left<right && nums[right]==nums[right+1]) right--;
            }else if(nums[i]+nums[left]+nums[right]<0){
                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
            }else{
                res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                while(left<right && nums[right]==nums[right-1]) right--;
                while(left<right && nums[left]==nums[left+1]) left++;

                right--;
                left++;
            }
        }
    }
    return res;
} 
int main(){
    vector<int>  nums={-1,0,1,2,-1,-4};
    vector<vector<int> > res=threeSum(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}