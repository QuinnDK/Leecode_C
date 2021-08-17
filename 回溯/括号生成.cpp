#include<iostream>
#include<vector>
#include<string>
using namespace std;

void backtrack(int left,int right,string& track,vector<string>& res);
vector<string> generateParenthesis( int n){
    vector<string> res;
    if (n==0) return res;
    string track;
    backtrack(n,n,track,res);
    return res;
}

void backtrack(int left,int right,string& track,vector<string>& res){
    if (left<0|| right<0) return;
    if (right<left) return;
    if(left==0&&right==0){
        res.push_back(track);
        return ;
    }
    track.push_back('(');
    backtrack(left-1,right,track,res);
    track.pop_back();

    track.push_back(')');
    backtrack(left,right-1,track,res);
    track.pop_back();
}