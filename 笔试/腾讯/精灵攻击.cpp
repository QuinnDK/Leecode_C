#include<bits/stdc++.h>
using namespace std;

int numOfYin(int n){
    int res=0;
    for(int i=1;i<=sqrt(n)+1;i++){
        int temp1=i;
        int temp2=n/i;

        if(temp1*temp2!=n){
            continue;
        }
        if(temp1>temp2){
            break;
        }
        if(temp1==temp2){
            res++;
            break;
        }
        res+=2;
    }
    return res;
}

int main(){
    int n;
    cin >>n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        A[i] = numOfYin(A[i]);
        B[i] = numOfYin(B[i]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res=0;
    int j=n-1;
    for(int i=n-1;i>=0;i--){
        while(j>=0){
            if(A[i]>B[j]){
                res++;
                j--;
                break;
            }
            j--;
        }
        cout<<res<<endl;
    }
    cout << res; 
}