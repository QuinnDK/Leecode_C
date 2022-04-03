#include<bits/stdc++.h>
using namespace std;

stack<int> stackIn;
stack<int> stackOut;

void MyQueue(){

}

void push(int x){
    stackIn.push(x);
}

int pop(){
    if(stackOut.empty()){
        while(!stackIn.empty()){
            stackOut.push(stackIn.top());
            stackIn.pop();
        }

    }
    int res=stackOut.top();
    stackOut.pop();
    return res;
}

int peek(){
    int res=pop();
    stackOut.push(res);
    return res;
}

bool empty(){
    return stackIn.empty() && stackOut.empty();
}
