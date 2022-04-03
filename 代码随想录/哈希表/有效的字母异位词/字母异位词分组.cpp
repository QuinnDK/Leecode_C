#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool isAnagram(string s,string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t){
        return true;
    }
    return false;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    unordered_map<string,int> map;
    for(auto& x:strs){
        map[x]++;
    }
    for(int i=0;i<strs.size();i++){
        vector<string> tmp;
        if(map[strs[i]]>0){
            tmp.push_back(strs[i]);
            map[strs[i]]--;
        }
        for(int j=0;j<strs.size();j++){
            if(isAnagram(strs[i],strs[j])&& map[strs[j]]>0){
                tmp.push_back(strs[j]);
                map[strs[j]]--;
            }else{
                continue;
            }
        }
        if(tmp.empty()) continue;
        res.push_back(tmp);
    }
    return res;
}

vector<vector<string> > groupAnagrams1(vector<string>& strs) {
    unordered_map<string, vector<string> > mp;
    for (string& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }
    vector<vector<string> > ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.push_back(it->second);
    }
    return ans;
} 