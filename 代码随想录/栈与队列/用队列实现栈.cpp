#include<bits/stdc++.h>
using namespace std;

queue<int> que1;
queue<int> que2;

MyStack(){

}

void push(int x){
    que1.push(x);
}

int pop(){
    int size=que1.size();
    size--;
    while(size--){
        que2.push(que1.front());
        que1.pop();
    }
    int result=que1.front();
    que1.pop();
    que1=que2;
    while(!que2.empty()){
        que2.pop();
    }
    return result;
}

int top(){
    return que1.back();
}
bool empty(){
    return que1.empty();
}

