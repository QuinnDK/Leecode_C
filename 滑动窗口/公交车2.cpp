#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> record(n);
    double average = -1.0;
    
    for (int i=0;i<n;i++){
        cin>>record[i];
    }
    vector<int> preSum(n+1);
    for (int i=1;i<=n;i++){
        preSum[i]=preSum[i-1]+record[i-1];
    }
    // for (int i=1;i<=n;i++){
    //     cout<<preSum[i]<<endl;
    // }
    // (sum*(j-i)==temp*(end-start))
    long sum=0;
    int start=0;
    int end=0;
    for (int i=0;i<=n-k;i++){
        for (int j=i+k;j<=n;j++){
            int temp=preSum[j]-preSum[i];
            if((sum*(j-i)<=temp*(end-start)) && (j-i)>(end-start)){
                sum=temp;
                end=j;
                start=i;
            }
        }
    }
    cout<<start<<" "<<end-1<<endl;
}