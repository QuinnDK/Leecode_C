#include<bits/stdc++.h>
using namespace std;


void MapSort(vector<pair<int,int> >& nums,unordered_map<int,int>& map){
    for(unordered_map<int,int>::iterator it=map.begin();it!=map.end();it++){
        nums.push_back(make_pair(it->second,it->first));
    }
    sort(nums.begin(),nums.end());
}
vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    vector<pair<int,int> > res;
    MapSort(res,map);
    vector<int> result;
    for(vector<pair<int,int> >::iterator it=res.end();it>res.end()-k;it--){
        result.push_back(it->second);
    }
    return result;
}

static int cmp(const pair<int,int>& x,const pair<int,int>& y) {
    return x.second>y.second;
}
vector<int> topKFrequent1(vector<int>& nums, int k){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    vector<pair<int,int> > res(map.begin(),map.end());
    // struct{
    //     bool operator()(const pair<int,int>& x,const pair<int,int>& y) const {return x.second>y.second;}
    // }cmp;
    //sort(res.begin(),res.end(),cmp);
    sort(res.begin(),res.end(),[]( pair<int,int>& x, pair<int,int>& y){
        return x.second>y.second;
    });
    vector<int> result;
    for(int i=0;i<k;i++){
        result.push_back(res[i].first);
    }
    return result;
}

int main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    vector<int> res;
    res=topKFrequent1(nums,k);
    for(auto& x:res){
        cout<<x<<" ";
    }
    cout<<endl;
}