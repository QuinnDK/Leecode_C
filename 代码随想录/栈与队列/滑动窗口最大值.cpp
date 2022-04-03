#include<bits/stdc++.h>
using namespace std;

//超时
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     int flag=k;
//     for(int fast=0;fast+flag<=nums.size();fast++){
//         int num=nums[fast];
//         while(flag>1){
//             if(nums[fast+flag-1]>num){
//                 num=nums[fast+flag-1];
//             }
//             flag--;
//         }
//         res.push_back(num);
//         flag=k;
//     }
//     return res;
// }
class Solution{
private:
    class MyQueue{
    public:
        deque<int> que;

        void pop(int value){
            if(!que.empty() && value==que.front()){
                que.pop_front();
            }
        }

        void push(int value){
            while(!que.empty() && value>que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }

};



int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> res;
    res=maxSlidingWindow(nums,k);
    for(auto& x: res){
        cout<<x<<" ";
    }
    cout<<endl;
}