#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,P;
    int res=INT_MIN;
    vector<int> nums(n);
    //存水量
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    
    vector<vector<int> > road(n+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       road[a][b]=c;
       road[b][a]=c;
    }
    int id=0;
    vector<vector<int> > dp(n+1,vector<int>(P+1,0));
    for(int i=0;i<n;i++){
        id=i;
        for (int j=0;j<n;j++){
            for(int k=0;k<=P;k++){
                if(k<2*road[i][j]){
                    dp[j][k]=dp[j-1][k];
                }else{
                    dp[j][k]=max(dp[j-1][k],dp[j-1][k-2*road[i][j]]+nums[j]);
                }
            }
        }
    }
    
    cout<<id<<" "<<dp[n][P];
}
