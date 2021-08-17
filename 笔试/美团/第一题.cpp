#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin>>nums[i];
         
        sort(nums.begin(),nums.end());

        if (nums[k]!=nums[k-1] && nums[k-1]+1<=n) cout<<"YES"<<nums[k-1]+1<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}