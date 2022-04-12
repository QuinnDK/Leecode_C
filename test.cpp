#include<bits/stdc++.h>
using namespace std;

bool isUp(char a){
    return a>='A'&& a<='Z';
}
void sortLetters(string& s){
    int i=0,j=s.size()-1;
    while(i<j){
        while(i<j&&!isUp(s[i])){
            i++;
        }
        while(i<j&&!isUp(s[j])){
            j--;
        }
        if(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
}
int main(){
    // vector<vector<int> > nums={{1,2},{2,4},{1,3},{3,5},{4,6}};
    // sort(nums.begin(),nums.end(),[](vector<int>& a,vector<int>& b){
    //     if(a[0]!=b[0]){
    //         return a[0]<b[0];
    //     }else{
    //         return a[1]>b[1];
    //     }
    // });
    // for(int i=0;i<nums.size();i++){
    //     for(int j=0;j<nums[i].size();j++){
    //         cout<<nums[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string str="CBAcbad";
    sortLetters(str);
    cout<<str<<endl;
}