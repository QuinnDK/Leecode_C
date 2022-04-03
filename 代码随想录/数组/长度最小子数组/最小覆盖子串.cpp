#include<bits/stdc++.h>
using namespace std;


// string minWindow1(string s, string t){
//     unordered_map<char,int> mapt;
//     for(int i=0;i<t.size();i++){
//         mapt[t[i]]++;
//     }
//     int l=0,r=0;
//     int res=INT32_MAX;
//     int slow=0;
//     for(int fast=0;fast<s.size();fast++){
//         mapt[s[fast]]++;
//         while(mapt.size()>0){
//             mapt[s[slow]]--;
//             if(mapt[s[slow]]==0){
//                 mapt.erase(s[slow]);
//             }
//             slow++;
//         }
//         int cout=res>fast-slow+1 ? fast-slow+1 :res;
//         if(cout<res){
//             res=cout;
//             l=slow;
//             r=fast;
//         }
//     }
//     return s.substr(l,r);
// }

string minWindow(string s,string t){
    unordered_map<char,int> maps,mapt;
    for(int i=0;i<t.size();i++){
        mapt[t[i]]++;
    }

    string  res;
    int count=0;

    for(int slow=0,fast=0;fast<s.size();fast++){
        maps[s[fast]]++;
        if(maps[s[fast]]<=mapt[s[fast]]){
            count++;
        }
        while(maps[s[slow]]>mapt[s[slow]]){
            maps[s[slow++]]--;
        }
        if(count==t.size()){
            if(res.empty() || fast-slow+1<res.size())
            res=s.substr(slow,fast-slow+1);
        }
    }
    return res;
}

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<minWindow(s,t);
}