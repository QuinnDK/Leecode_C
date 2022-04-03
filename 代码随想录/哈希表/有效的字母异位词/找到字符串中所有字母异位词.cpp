#include<bits/stdc++.h>
using namespace std;

//超时
// bool isAnagram(string s,string t){
//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());
//     if(s==t){
//         return true;
//     }
//     return false;
// }

// vector<int> findAnagrams(string s,string p){
//     int len=p.size();
//     vector<int> res;
//     for(int i=0;i<=s.size()-len+1;i++){
//         int x=i;
//         if(isAnagram(p,s.substr(x,len))){
//             res.push_back(x);
//         }
//     }
//     return res;
// }

vector<int> findAnagrams(string s,string p){
    vector<int> res;
    int m=s.size();
    int n=p.size();
    if(m<n) return res;
    vector<int> window(26,0);
    vector<int> st(26,0);
    for(auto& x:p){
        st[x-'a']++;
    }
    int slow=0;
    for(int fast=0;fast<m;fast++){
        window[s[fast]-'a']++;
        if(fast>=n){
            window[s[slow++]-'a']--;
        }
        if(window==st){
            res.push_back(slow);
        }
    }
    return res;
}
int main(){
    string s="abab";
    string p="ab";
    vector<int > res=findAnagrams(s,p);
    for(auto& x:res){
        cout<<x<<" ";
    }

}