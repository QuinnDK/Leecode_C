#include<bits/stdc++.h>
using namespace std;
int M;
int N;
int i,j;
vector<vector<int> > nums(20,vector<int>(20,2));
int dfs(int x,int y){
    if(x>=0 && x<=M && y>=0 && y<N && nums[x][y]==1){
        nums[x][y]=0;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
    return 0;
}

int main(){
    
    cin>>M;
    cin>>N;
    int count=0;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>nums[i][j];
        }
    }

    for(i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(nums[i][j]==1 ){
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
}