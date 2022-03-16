#include<bits/stdc++.h>
using namespace std;

string intToB(int num){
    string res;
    while(num){
        int num1=num%10;
        num=num/10;
        string res1;
        while(num1){
            res1+=to_string(num1%2);
            num1/=2;
            reverse(res.begin(), res.end());
        }
        res+=res1;
        res1="";
    }
    return res;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        string B =intToB(num);
        string str;
        for(int i=0;i<B.size();i++){
            if(B[i]=='0'){
                i++;
            }
            str+=B[i];
            for(int j=i;j<B.size();j++){
                if(B[j]==B[i]){
                    j++;
                }else{
                    str+=B[j];
                    i=j;
                }
            }
        }
        cout<<str<<endl;
    }
}