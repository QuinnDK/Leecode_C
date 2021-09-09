#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

int main()
{
    string s;
    cin>>s;
    int M=0,N=0;
    //min_len=M-1+N-1+1;
    int t=0;
    while(s[t]!=','){
        M*=10;
        M+=s[t]-'0';
        t++;
    }
    t++;
    while(t<s.size()){
        N*=10;
        N+=s[t]-'0';
        t++;
    }
    if(M==0 || N==0){
        cout<<-1;
        return 0;
    }
    vector<vector<int> > nums(M,vector<int>(N));
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>nums[i][j];
        }
    }
   
    vector<vector<int> > dp(M,vector<int>(N,-1));
    dp[0][0]=0;
    for(int i=1;i<N;i++){
        if(nums[0][i]==0)continue;
        int Min=INT8_MAX;
        bool flag=false;
        for(int j=0;j<i;j++){
            if(dp[0][j]!=-1 && nums[0][j]+j>=i){
                flag=true;
                Min=min(Min,dp[0][j]);
            }
        }
        if(flag)dp[0][i]=Min+1;
        else dp[0][i]=-1;
    }
    
    for(int i=1;i<M;i++){
        if(nums[i][0]==0)continue;
        int Min=INT8_MAX;
        bool flag=false;
        for(int j=0;j<i;j++){
            if(dp[j][0]!=-1 && nums[j][0]+j>=i){
                flag=true;
                Min=min(Min,dp[j][0]);
            }
        }
        if(flag)dp[i][0]=Min+1;
        else dp[i][0]=-1;
    }
    
    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            if(nums[i][j]==0)continue;
        
            int up=INT8_MAX;
            int left=INT8_MAX;
            bool flag=false;
            for(int k=0;k<i;k++){
                if(dp[k][j]!=-1 && nums[k][j]+k>=i){
                    flag=true;
                    up=min(up,dp[k][j]);
                }
            }
            for(int k=0;k<j;k++){
                if(dp[i][k]!=-1 && nums[i][k]+k>=j){
                    flag=true;
                    left=min(up,dp[i][k]);
                }
            }
            if(flag)dp[i][j]=min(up,left)+1;
        }
    }
    /*
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[M-1][N-1]<<endl;
    return 0;
}