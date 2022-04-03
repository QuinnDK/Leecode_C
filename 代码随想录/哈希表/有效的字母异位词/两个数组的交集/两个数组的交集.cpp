#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    int len1=nums1.size();
    int len2=nums2.size();

    if(len1<len2){
        swap(len1,len2);
        swap(nums1,nums2);
    }
    vector<int> res;
    unordered_map<int,int> map;
    for(auto& x:nums2){
        map.insert(make_pair(x,1));
    }
    set<int > set;
    for(auto& x:nums1){
        set.insert(x);
    }
    for(auto& x:set){
        if(map.count(x)){
            res.push_back(x);
        }
    }
    return res;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> result_set; // 存放结果
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2) {
        // 发现nums2的元素 在nums_set里又出现过
        if (nums_set.find(num) != nums_set.end()) {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}