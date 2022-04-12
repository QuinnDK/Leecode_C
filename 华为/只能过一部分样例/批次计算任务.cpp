#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=0,m=0;
    cin>>n>>m;

    vector<int> nums(n+2,0);
    for(int i=1;i<n;i++){
        cin>>nums[i];
    }
    int num1=0,num2=0;
    nums[n+1]=10000;
    int slow=0,fast=0;
    int res=0;
    for(int i=0;i<n+2;i++){
        slow=nums[i];
        if(i+m+1>n+1){
            break;
        }
        fast=nums[i+m+1];
        if(res<fast-slow){
            res=fast-slow;
            num1=slow;
            num2=fast;
        }
        
    }
    if(num1!=0 && num2!=10000){
        res--;
    }
    cout<<res<<endl;
}