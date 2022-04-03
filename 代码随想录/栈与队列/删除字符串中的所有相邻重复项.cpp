#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<char> sta;
    for(auto& x:s){
        if(sta.empty()){
            sta.push(x);
        }else{
            if(x==sta.top()){
                sta.pop();
            }else{
                sta.push(x);
            }
        }
    }
    string res;
    while(!sta.empty()){
        res+=sta.top();
        sta.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}