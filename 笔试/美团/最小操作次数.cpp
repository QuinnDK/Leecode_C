#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    int res=0;
    cin>>N;
    vector<int>data(N);
    for (int i=0;i<N;i++){
       cin>>data[i];
    }

    for (int i=0;i<N/2;i++){
        if (data[i]!=data[i+(N/2)]){
            res++;
        }
    }
    cout<<res<<endl;
}