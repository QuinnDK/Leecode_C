#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; 
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    int res=0;

    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    for(int i=0;i<n;i++){
       cin>>b[i];
    }
    for(int i=0;i<n;i++){
       cin>>c[i];
    }

    for(int i=0;i<n;i++){
        res+=min(min(a[i],b[i]),c[i]);
    }
    cout<<res;

}