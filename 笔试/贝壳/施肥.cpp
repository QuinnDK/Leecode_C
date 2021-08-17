#include<iostream>
#include<vector>
using namespace std;

vector<int> fun(int n, int m){

    int num=m/(n-1);
    vector<int>res(n,num);
    int flag=m%(n-1);
    if (num%2==0){
        res[0]/=2;
        res[n-1] /=2;
        for (int i=i;i<flag;i++){
            res[i]++;
        }
    }else{
        res[0]/=2;
        res[0]++;
        res[n-1] /=2;
        for (int i=0;i<flag;i++){
            res[n-1-i]++;
        }
    }
    return res;
}

int main(){
    vector<int> res;
    int n,m;
    cin>>n>>m;
    res=fun(n,m);
    for (auto& it :res){
        cout<<it;
    }
}
