#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<string>> res;


bool isValid(vector<string>& board,int row,int col){
    int n=board.size();
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return false;
    }
    for(int i=row-1;j=col+1;i>=0&&j<n; i--,j++){
        if(board[i][j]=='Q') return false;
    }
    for(int i=row-1,j=col-1;i>=0&& j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }
    return true;
}
void backstrack(vector<string>& board,int row){
    if(row==board.size()){
        res.push_back(board);
        return;
    }
    int n=board[row].size();
    for(int col=0;col<n;col++){
        if(!isValid(board,row,col)) continue;
        
        board[row][col]='Q';
        backstrack(board,row+1);
        board[row][col]='.';
    }
}
vector<vector<string>> solve(int n){
    vector<string> board(n,string(n,'.'));
    backstrack(board,0);
    return res;
}

int main(){
    string n;
    int num=-1;
    cin>>n;
    //有问题
    for (auto it:n){
        if(it>='0'&& it<='9'){
            num=it;
        }
    }
    solve(num);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j];
        }
    }
}