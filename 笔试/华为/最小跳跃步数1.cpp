#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    stringstream t(str);
    vector<int> num;

    while(getline(t,str,',')){
        int t=stoi(str);
        num.push_back(t);
    }

    int m=num[0];
    int n=num[1];
    vector<vector<int> > nums(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    
    vector<vector<int> > dp(m,vector<int>(n,-1));
    dp[0][0]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==-1) continue;
            int jump=nums[i][j];
            for(int z=1;z<=jump && i+z<m;z++){
                if(dp[i+z][j] != -1){
                    dp[i+z][j] =min(dp[i+z][j],dp[i][j]+1);
                }else{
                    dp[i+z][j] =dp[i][j]+1;
                }
            }
            for(int z=1;j<=jump && j+z<n;z++){
                if(dp[i][j+z] != -1){
                    dp[i][j+z] =min(dp[i][j+z],dp[i][j]+1);
                }else{
                    dp[i][j+z] =dp[i][j]+1;
                }
            }
        }
    }
    return dp[m-1][n-1];
}