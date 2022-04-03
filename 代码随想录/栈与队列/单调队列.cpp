#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    deque<int> que;

    void pop(int value){
        if(!que.empty() && value==que.front()){
            que.pop_front();
        }
    }

    void push(int value){
        while(!que.empty() && value>que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int front(){
        return que.front();
    }
};
