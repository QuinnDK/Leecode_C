#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,p,q;
    cin>>n>>p>>q;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());

    int res=0;
    int flag=100;
    for(int i=n-1;i>=0;i--){
        if(i<n-1 && nums[i]<nums[n+1]){
            flag--;
        }
        double C=(nums[i]*q+flag*p)/100.0;
        if(C>=60.0){
            res++;
        }
    }
    // if((nums[0]*p+flag*q)/100>60.0){
    //     res++;
    // }else{
    //     return res;
    // }
    
    // for(int i=1;i<n;i++){
    //     double C=(nums[i]*p+flag*q)/100;
    //     if( C>60.0){
    //         res++;
    //     }
    //     if(nums[i]!=nums[i-1]){
    //         flag--;
    //     }
    // }
    cout<<res;
}