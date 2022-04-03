#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    int left=0;
    int right=s.size()-1;
    stack<string> sta;
    string str;
    while(left<=right){
        if(s[left]!=' '){
            str+=s[left];
            if(s[left+1]==' ' || left==right){
                sta.push(str);
                str="";
            }
        }
        left++;
    }
    string res;
    while(!sta.empty()){
        res+=sta.top();
        sta.pop();
        if(!sta.empty()){
            res+=' ';
        }
    }
    return res;
}