#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
int main(){
    string input,s;
    int n;
    vector<int> nums;
    cin>>input;
    istringstream ss(input);

    while(getline(ss,s,',')){
        n=atoi(s);
        nums.push_back(n);
    }
    cin>>n;
    n%=nums.size();
    for (int i=0;i<nums.size();i++){
        if (i<n){
            cout<<nums[(i+nums.size()-n)];
        }else{
            cout<<nums[(i-n)%nums.size()];
        }
        if (i!=nums.size()-1){
            cout<<",";
        }
    }
    return 0;
}