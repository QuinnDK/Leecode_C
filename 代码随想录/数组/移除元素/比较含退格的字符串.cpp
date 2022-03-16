#include<bits/stdc++.h>
using namespace std;

void change(string& str){
    int slow=0;
    for(int fast=0;fast<str.size();fast++){
        if(str[fast]!='#'){
            str[slow++]=str[fast];
        }else if(slow!=0){
            slow--;
        }
    }
    str.resize(slow);
}

bool backspaceCompare(string s, string t){
    change(s);
    change(t);
    return s==t;
}