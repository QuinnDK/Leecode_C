#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > threeNums(vector<int>& nums);
int main(){
    vector<int> nums;
    int n;
    while (cin>>n){
        nums.push_back(n);
    }
    vector<vector<int> > ret=threeNums(nums);
    for(int i=0;i<ret.size();i++){
        for (int j=0;j<ret[0].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

vector<vector<int> > threeNums(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;

    for(int i=0;i<n-2;i++){
        if (i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int low=i+1,high=n-1;
        while (low<high){
            if (nums[i]+nums[low]+nums[high]==0){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[low]);
                temp.push_back(nums[high]);
                res.push_back(temp);
                while (low<high && nums[low+1]==nums[low]) low++;
                while (low<high && nums[high-1]==nums[high]) high--;
            }else if (nums[i]+nums[low]+nums[high]<0){
                low++;
            }else{
                high--;
            }
        }
    }
    return res;
}