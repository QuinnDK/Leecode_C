#include<iostream>
#include<vector>
using namespace std;

int count(vector<int> arr){
    int co;
    for (int i=0;i<arr.size()-2;i++){
        for (int j=i+1;j<arr.size()-1;j++){
            for (int k=j+1;k<arr.size();k++){
                if (((arr[i]<arr[j])&&(arr[j]<arr[k])) || ((arr[i]>arr[j])&&(arr[j]>arr[k]))){
                    co++;
                }
            }
        }
    }
    return co;
}

int main(){
    //int n;
    vector<int> arr = {1 ,5, 3, 2, 4};
    // while(cin>>n){
    //     arr.push_back(n);
    // }
    sort(arr.begin(),arr.end());
    int res= count(arr);
    cout<<res;
}