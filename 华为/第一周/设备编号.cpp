#include<bits/stdc++.h>
using namespace std;

int GetNormalDeviceNum(int start,int end) const 
{
    int result=0;

    for(int i=start;i<=end;i++){
        int sw=i/100000;
        int i1=i%100000;

        int w=i1/10000;
        int i2=i1%10000;

        int q=i2/10000;
        int i3=i2%10000;

        int b=i3/10000;
        int i4=i3%10000;

        int s=i4/10000;
        int g=i4%10000;
        vector<int> nums={sw,w,q,b,s,g};
        if(nums[0]==4 || nums[1]==4 ||nums[2]==4 ||nums[3]==4 ||nums[4]==4 || nums[5]==4 ){
            continue;
        }else if(nums[0]*10+nums[1]==18){
            continue;
        }else if(nums[1]*10+nums[2]==18){
            continue;
        }else if(nums[2]*10+nums[3]==18){
            continue;
        }else if(nums[3]*10+nums[4]==18){
            continue;
        }else if(nums[4]*10+nums[5]==18){
            continue;
        }else{
            result++;
        }
    }
    return result;
}