#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<int,int> findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size()){
            k = nums.size();
        }
        int temp_ret = nums[0];
        int ret = temp_ret;
        int left = 0;
        int right;
        unordered_map<int,int> map;
        for (right = 1; right < nums.size(); ++right) {
            if (right - left + 1 <= k+1){
                temp_ret += nums[right];
                ret = temp_ret;
                map.insert(make_pair(ret,right));
            }else{
                temp_ret -= nums[left];
                left++;
                temp_ret += nums[right];
                if (temp_ret > ret){
                    ret = temp_ret;
                    cout<<ret;
                    map.insert(make_pair(ret,right));
                }
            }
        
        }
        return map;
}
int main(){
    unordered_map<int,int> res;
    vector<int> nums ={1,2,3,1,1,2,2,2,2};
    //nums.push_back(1);nums.push_back(3);nums.push_back(2);nums.push_back(3);nums.push_back(1);nums.push_back(2);nums.push_back(2);nums.push_back(2);nums.push_back(2);
    int k=3;
    res=findMaxAverage(nums,k);
    int a=res[0];
    int index=0;
    unordered_map<int,int>::iterator it;
    for(it=res.begin();it!=res.end();it++){
        if (it->first >a){
            index=it->second;
            //cout<<it->first<<endl;
        }
    }
    cout<<index-3<<" "<<index;
}