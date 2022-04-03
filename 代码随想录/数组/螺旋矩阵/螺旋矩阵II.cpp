#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generateMatrix(int n){
    vector<vector<int> > res(n,vector<int>(n,0));
    int num=1;
    int top=0,left=0;
    int bottom=n-1,right=n-1;
    while(num<=n*n){
        for(int i=left;i<=right;i++){
            res[top][i]=num++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[i][right]=num++;
        }
        right--;
        for(int i=right;i>=left;i--){
            res[bottom][i]=num++;
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            res[i][left]=num++;
        }
        left++;
    }
    return res;
}
int main(){
    vector<vector<int> > nums=generateMatrix(3);
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}