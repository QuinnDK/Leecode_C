#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> str;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') str.push(')');
        else if(s[i]=='[') str.push(']');
        else if(s[i]=='{') str.push('}');
        else if(str.empty() || str.top()!=s[i]){
            return false;
        }else{
            str.pop();
        }
    }
    return str.empty();
}