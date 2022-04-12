#include<bits/stdc++.h>
using namespace std;

vector<char> GetNTimesCharacter(int n, const vector<string> &strings)
{
    //vector<char> result;
    int m=strings.size();
    vector<vector<int> > res(m,vector<int>(256,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<strings[i].size();j++){
            res[i][strings[i][j]]++;
        }
    }
    vector<char> ans;
    for(int i=48;i<=57;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(res[j][i]>=n){
                count++;
            }
        } 
        if(count==m){
            ans.push_back(i);
        }
    }
    for(int i=65;i<=90;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(res[j][i]>=n){
                count++;
            }
        } 
        if(count==m){
            ans.push_back(i);
        }
    }
    for(int i=97;i<=122;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(res[j][i]>=n){
                count++;
            }
        } 
        if(count==m){
            ans.push_back(i);
        }
    }
    return ans;
}
