#include<bits/stdc++.h>
using namespace std;

int newN(int n){
    int sum=0;
    while(n){
        sum+=(n%10) * (n%10);
        n=n/10;
    }
    return sum;
}
bool isHappy(int n){
    unordered_set<int> set;
    while(n!=1){
        if(set.find(n)==set.end()){
            set.insert(n);
        }else{
            return false;
        }
        n=newN(n);
    }
    return true;
}