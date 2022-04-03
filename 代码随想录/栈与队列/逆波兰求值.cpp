#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> sta;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]=="+" ||tokens[i]=="-"|| tokens[i]=="*" || tokens[i]=="/"){
            int num1=sta.top();
            sta.pop();
            int num2=sta.top();
            sta.pop();
            if(tokens[i]=="+") sta.push(num1+num2);
            if(tokens[i]=="-") sta.push(num2-num1);
            if(tokens[i]=="*") sta.push(num2*num1);
            if(tokens[i]=="/") sta.push(num2/num1);
        }else{
            sta.push(stoi(tokens[i]));
        }
    }
    int res=sta.top();
    sta.pop();
    return res;
}