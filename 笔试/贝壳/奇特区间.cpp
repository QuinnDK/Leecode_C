#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool QY(vector<int>& nums,int t){
    for (int i=0;i<nums.size()-1;i++){
        for (int j=0;j<nums.size();j++){
            if ((nums[i]^nums[j])==t){
                return false;
            }
        }
    }
    return true;
}

int select(vector<int>& a,int t){
    int res=0;
    for (int i=0;i<a.size();i++){
        for(int j=a.size()-1;j>i;j--){
            vector<int > nums(a.begin()+i,a.begin()+j);
            if(QY(nums,t)&&(i<j)){
                res++;
                //cout<<res;
            }
        }
    }
    return res;
}


long section(vector<int> a, int t) {
    long n = a.size();
    long res = 0;
    unordered_map<int, long> m;
    m[a[0]] = 0;
    long flag = -1;
    
    for (long i = 1; i < n; i ++ ) {
        int temp = t ^ a[i];
        if(!m.count(temp)){
            res += i - flag - 1;
        }
        else {
            flag = max(flag, m[temp]);
            res += i - flag - 1;
        }
            
        m[a[i]] = i;
    }
    
    return res;
    
}


// long section(vector<int> a,int t){
//     long ans=0;
//     for (int i=0;i<a.size();++i){
//         int j=i+1;
//         while (j<a.size()){
//             if((a[i]^a[j])==t){
//                 ++ans;
//                 cout<<i<<" "<<j;
//                 break;
//             }
//             j++;
//         }
//     }
//     return ans;
// }
int main(){
    vector<int> nums={2,3,4};
    int t=6;
    cout<< section(nums,t);
}