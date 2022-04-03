#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    int m=matrix.size();
    int n=0;
    if(m>0){
        n=matrix[0].size();
    }      
    vector<int> res(m*n);
    int a=0;
    int top=0,left=0;
    int bottom=m-1,right=n-1;
    while(true){
        for(int i=left;i<=right;i++){
            res[a++]=matrix[top][i];
        }
        top++;
        if(top>bottom) break;
        for(int i=top;i<=bottom;i++){
            res[a++]=matrix[i][right];
        }
        right--;
        if(right<left) break;
        for(int i=right;i>=left;i--){
            res[a++]=matrix[bottom][i];
        }
        bottom--;
        if(bottom<top) break;
        for(int i=bottom;i>=top;i--){
            res[a++]=matrix[i][left];
        }
        left++;
        if(left>right) break;
    }
    return res;
}

int main(){

}