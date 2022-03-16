#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height){
    int res=0;
    int i=0;
    int j=height.size()-1;

    while(i<j){
        int num=(j-i) * min(height[i],height[j]);
        res=max(res,num);
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }
    }
    return res;
}

int main(){
    vector<int> num={4,3,2,1,4};
    cout<<maxArea(num)<<endl;
}