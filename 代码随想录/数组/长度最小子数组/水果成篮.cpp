#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits){
    int slow=0;
    unordered_map<int,int> map;
    int res=0;
    for(int fast=0;fast<fruits.size();fast++){
        map[fruits[fast]]++;
        while(map.size()>2){
            map[fruits[slow]]--;
            if(map[fruits[slow]]==0){
                map.erase(fruits[slow]);
            }
            slow++;
        }
        res=res<fast-slow+1? fast-slow+1 : res;
    }
    return res;
}